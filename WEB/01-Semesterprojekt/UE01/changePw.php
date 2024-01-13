<?php
session_start();

// Check if the user is logged in
if (!isset($_SESSION['loggedin'])) {
    // User is not logged in. Redirect them to the login page
    header('Location: login.php');
    exit;
}

// User's data for this example
$role = $_SESSION['u_role'];
$username = $_SESSION['u_username'];
$fname = $_SESSION['u_firstname'];
$lname = $_SESSION['u_lastname'];
$email = $_SESSION['u_email'];
$title = $_SESSION['u_title'];
$gender = $_SESSION['u_gender'];
$id = $_SESSION['u_id'];

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    // Update the user's data based on the form inputs
    $fname = $_POST['fname'];
    $lname = $_POST['lname'];
    $email = $_POST['email'];
    $title = $_POST['title'];
    $gender = $_POST['gender'];

    // Perform validation and update database or session data as needed
    // ...

    // Optionally, redirect the user to a different page after successful update
    header('Location: profil.php');
    exit;
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
                                <button type="submit" name="submit" class="btn btn-primary btn-margin">Confirm</button>    
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
