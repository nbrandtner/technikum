<?php
session_start();

// Check if the user is logged in
if (!isset($_SESSION['loggedin'])) {
    // User is not logged in. Redirect them to the login page
    header('Location: login.php');
    exit;
}
include 'db_config.php';

// User's data for this example
$username = $_SESSION['u_username'];
$fname = $_SESSION['u_firstname'];
$lname = $_SESSION['u_lastname'];
$email = $_SESSION['u_email'];
$title = $_SESSION['u_title'];
$gender = $_SESSION['u_gender'];
$id = $_SESSION['u_id'];

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    // Update the user's data based on the form inputs
    $username = $_POST['username'];
    $fname = $_POST['fname'];
    $lname = $_POST['lname'];
    $email = $_POST['email'];
    $gender = $_POST['gender'];

    // Check if the new email is already taken
    $checkEmailStmt = $mysqli->prepare("SELECT * FROM user WHERE u_email = ? AND u_id != ?");
    $checkEmailStmt->bind_param("si", $email, $id);
    $checkEmailStmt->execute();
    $checkEmailStmt->store_result();

    if ($checkEmailStmt->num_rows > 0) {
        // Email is already taken
        $checkEmailStmt->close();
        echo "Email is already taken. Choose a different one.";
        exit;
    }

    $checkEmailStmt->close();

    // Check if the new username is already taken
    $checkUsernameStmt = $mysqli->prepare("SELECT * FROM user WHERE u_username = ? AND u_id != ?");
    $checkUsernameStmt->bind_param("si", $username, $id);
    $checkUsernameStmt->execute();
    $checkUsernameStmt->store_result();

    if ($checkUsernameStmt->num_rows > 0) {
        // Username is already taken
        $checkUsernameStmt->close();
        echo "Username is already taken. Choose a different one.";
        exit;
    }

    $checkUsernameStmt->close();

    if ($gender == "male") {
        $title = "Mr.";
    } elseif ($gender == "female") {
        $title = "Mrs.";
    } elseif ($gender == "diverse") {
        $title = "Mx.";
    }
    // Prepare and execute the update query
    $stmt = $mysqli->prepare("UPDATE user SET u_username=?, u_firstname=?, u_lastname=?, u_email=?, u_title=?, u_gender=? WHERE u_id=?");
    $stmt->bind_param("ssssssi", $username, $fname, $lname, $email, $title, $gender, $id);

    // Execute the update
    if ($stmt->execute()) {
        // Set all Session Variables to the new values
        $_SESSION['u_username'] = $username;
        $_SESSION['u_firstname'] = $fname;
        $_SESSION['u_lastname'] = $lname;
        $_SESSION['u_email'] = $email;
        $_SESSION['u_title'] = $title;
        $_SESSION['u_gender'] = $gender;
        // Optionally, redirect the user to a different page after successful update
        header('Location: profil.php');
        exit;
    } else {
        // Handle the error, if any
        echo "Error updating user: " . $mysqli->error;
    }

    $stmt->close();
    $mysqli->close(); // Close the database connection
}
?>
<!DOCTYPE html>
<html lang="en">
    <?php include 'htmlhead.php'; ?>
    <body>
    <header>
        <a href="index.php"><img src="img/logo-transparent.png" width="330px"></a>
        <div class="icon-container">
            <main>
                <div class="row justify-content-center">
                    <div class="col-md-10" style="color:white">  
                        <div class="about">
                            <form action="editProfil.php" method="post">
                                <h3 style="color:white;">Edit Profile</h3>
                                
                                <div class="form-group">
                                    <label style="color:white;" class="form-label">Gender:</label> 
                                    <div class="form-check form-check-inline">
                                        <input type="radio" name="gender" id="male" class="form-check-input input" value="male" <?php echo ($gender === 'male') ? 'checked' : ''; ?>>
                                        <label style="color:white;" class="form-check-label mr-3" for="male" alt="male">Male</label>
                                    </div>
                                    <div class="form-check form-check-inline">
                                        <input type="radio" name="gender" id="female" class="form-check-input input" value="female" <?php echo ($gender === 'female') ? 'checked' : ''; ?>>
                                        <label style="color:white;" class="form-check-label mr-3" for="female" alt="female">Female</label>
                                    </div>
                                    <div class="form-check form-check-inline">
                                        <input type="radio" name="gender" id="diverse" class="form-check-input input" value="diverse" <?php echo ($gender === 'diverse') ? 'checked' : ''; ?>>
                                        <label style="color:white;" class="form-check-label" for="diverse" alt="diverse">Diverse</label>
                                    </div>
                                </div>
                                <div class="row mb-3">
                                    <div class="col-md-6">
                                        <label style="color:white;" class="form-label" for="fname">First Name:</label>
                                        <input type="text" class="form-control" id="fname" name="fname" placeholder="Firstname" alt="Please enter your firstname" value="<?php echo $fname; ?>" required>
                                    </div>
                                    <div class="col-md-6">
                                        <label style="color:white;" class="form-label" for="lname">Last Name:</label>
                                        <input type="text" class="form-control" id="lname" name="lname" placeholder="Surname" alt="Please enter your surname" value="<?php echo $lname; ?>" required>
                                    </div>
                                </div>

                                <div class="row mb-3">
                                    <div class="col-md-6">
                                        <label style="color:white;" class="form-label" for="email">Email:</label>
                                        <input type="email" class="form-control" id="email" name="email" placeholder="E-Mail" alt="Please enter your E-Mail" value="<?php echo $email; ?>" required>
                                    </div>
                                    <div class="col-md-6">
                                        <label style="color:white;" class="form-label" for="username">Username:</label>
                                        <input type="text" class="form-control" id="username" name="username" placeholder="Username" alt="Please enter your Username" value="<?php echo $username; ?>" required>
                                    </div>
                                </div>
                                <br>
                                <div class="row mb-3">
                                    <div class="col-md-6">
                                        <button style="width:12vw" onclick="window.location.href='index.php'" type="button" class="glow-on-hover" alt="Back to Homepage">Back to Homepage</button>
                                    </div>
                                    <div class="col-md-6">
                                        <button style="width:12vw" name="submit" type="submit button" class="glow-on-hover" alt="Back to Homepage">Submit</button>
                                    </div>
                                </div>
                            </form>
                        </div>
                    </div>
                </div>
            </main>
        </div>
        </header>
        <footer>
            <p>&copy; <?php echo date("Y"); ?> Hotel Website</p>
        </footer>
        <script src="https://code.jquery.com/jquery-3.7.1.js" integrity="sha256-eKhayi8LEQwp4NKxN+CfCh+3qOVUtJn3QNZ0TciWLP4=" crossorigin="anonymous"></script>
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ka7Sk0Gln4gmtz2MlQnikT1wXgYsOg+OMhuP+IlRH9sENBO0LRn5q+8nbTov4+1p" crossorigin="anonymous"></script>
    </body>
</html>
