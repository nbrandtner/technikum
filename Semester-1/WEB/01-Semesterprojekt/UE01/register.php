<?php
session_start();
include 'db_config.php';

// define variables and set to empty values
$gender = $fname = $lname = $email = $username = $password = $password_repeat = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $gender = test_input($_POST["gender"]);
    $fname = test_input($_POST["fname"]);
    $lname = test_input($_POST["lname"]);
    $email = test_input($_POST["email"]);
    $username = test_input($_POST["username"]);
    $password = test_input($_POST["password"]);
    $password_repeat = test_input($_POST["password_repeat"]);

    // Check if all fields are filled
    if (empty($fname) || empty($lname) || empty($email) || empty($gender) || empty($password) || empty($password_repeat) || empty($username)) {
        $_SESSION['message'] = 'All fields must be filled out';
    } else {
        // Check if passwords match
        if ($password != $password_repeat) {
            $_SESSION['message'] = 'Passwords do not match';
        } else {
            // Check if email is valid
            if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
                $_SESSION['message'] = 'Invalid email format';
            } else {
                // Check if both username and email are unique
                $stmt = $mysqli->prepare("SELECT * FROM user WHERE u_username = ? OR u_email = ?");
                $stmt->bind_param("ss", $username, $email);
                $stmt->execute();
                $result = $stmt->get_result();
                $stmt->close();

                if ($result->num_rows > 0) {
                    $_SESSION['message'] = 'Username or Email already exists';
                } else {
                    if ($gender == "male") {
                        $title = "Mr.";
                    } elseif ($gender == "female") {
                        $title = "Mrs.";
                    } elseif ($gender == "diverse") {
                        $title = "Mx.";
                    }

                    $stmt = $mysqli->prepare("INSERT INTO user (u_firstname, u_lastname, u_role, u_pw, u_gender, u_status, u_title, u_email, u_username) VALUES (?, ?, 'user', ?, ?, 1, ?, ?, ?)");
                    $hashed_password = password_hash($password, PASSWORD_DEFAULT);

                    $stmt->bind_param("sssssss", $fname, $lname, $hashed_password, $gender, $title, $email, $username);
                    $stmt->execute();
                    $stmt->close();

                    $_SESSION['message'] = 'Registration successful';
                    header("Location: index.php");
                }
            }
        }
    }
    $mysqli->close(); // Close the database connection
}

function test_input($data)
{
    global $mysqli;
    $data = trim($data);
    $data = stripslashes($data);
    $data = htmlspecialchars($data);
    return $data;
}
?>

<!DOCTYPE html>
<html lang="en">
    <?php include 'htmlhead.php'; ?>
    <body>
        <?php
          include 'header.php';
        ?>
                <main>
                    <div class="row justify-content-center">
                        <h1 class="blackcolor">Register</h1>
                        <hr>
                        </br>
                            <form action="<?php echo $_SERVER["PHP_SELF"];?>" method="post">
                                <?php
                                if(isset($_SESSION['message'])) {
                                    if($_SESSION['message'] == 'Registration successful') {
                                        echo '<div class="success-message alert alert-success" role="alert">' . $_SESSION['message'] . '</div>';
                                        unset($_SESSION['message']);
                                    } else {
                                        echo '<div class="error-message alert alert-danger" role="alert">' . $_SESSION['message'] . '</div>';
                                        unset($_SESSION['message']);
                                    }
                                }
                                ?>
                                <div class="form-group">
                                    <label  class="form-label">Gender:</label> 
                                    <div class="form-check form-check-inline">
                                        <input type="radio" name="gender" id="male" class="form-check-input input" value="male" checked="">
                                        <label class="form-check-label mr-3" for="male" alt="male">Male</label>
                                    </div>
                                    <div class="form-check form-check-inline">
                                        <input type="radio" name="gender" id="female" class="form-check-input input" value="female">
                                        <label class="form-check-label mr-3" for="female" alt="female">Female</label>
                                    </div>
                                    <div class="form-check form-check-inline">
                                        <input type="radio" name="gender" id="diverse" class="form-check-input input" value="diverse">
                                        <label class="form-check-label" for="diverse" alt="diverse">Diverse</label>
                                    </div>
                                </div>
                                <div class="form-margin form-group"> 
                                    <input type="text" class="form-control" id="fname" name="fname" placeholder="Firstname" alt="Please enter your firstname" required>
                                </div>
                                <div class="form-group form-margin">
                                    <input type="text" class="form-control" id="lname" name="lname" placeholder="Surname" alt="Please enter your surname"required>
                                </div>
                                <div class="form-group form-margin">
                                    <input type="email" class="form-control" id="email" name="email" placeholder="E-Mail" alt="Please enter your E-Mail" required>
                                </div>
                                <div class="form-group form-margin">
                                    <input type="text" class="form-control" id="username" name="username" placeholder="Username" alt="Please enter your Username" required>
                                </div>
                                <div class="form-group form-margin">
                                    <input type="password" class="form-control" id="password" name="password" placeholder="Password" alt="Please enter your password" required>
                                </div>
                                <div class="form-group form-margin">
                                    <input type="password" class="form-control" id="password_repeat" name="password_repeat" placeholder="Confirm Password" alt="Please confirm your password" required>
                                </div>
                                <br>
                                <button name="submit" type="submit" class="btn btn-outline-primary" alt="Back to Homepage">Registrieren</button>
                            </form>
                    </div>
                </main>
        <footer>
            <p>&copy; <?php echo date("Y"); ?> Hotel Website</p>
        </footer>
        <script src="https://code.jquery.com/jquery-3.7.1.js" integrity="sha256-eKhayi8LEQwp4NKxN+CfCh+3qOVUtJn3QNZ0TciWLP4=" crossorigin="anonymous"></script>
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ka7Sk0Gln4gmtz2MlQnikT1wXgYsOg+OMhuP+IlRH9sENBO0LRn5q+8nbTov4+1p" crossorigin="anonymous"></script>
        <script>
        function logFormData(event) {
            event.preventDefault(); // prevent form submission
            var gender = document.getElementById('gender').value;
            var fname = document.getElementById('fname').value;
            var lname = document.getElementById('lname').value;
            var email = document.getElementById('email').value;
            var username = document.getElementById('username').value;
            var password = document.getElementById('password').value;

            console.log('Gender: ' + gender);
            console.log('First Name: ' + fname);
            console.log('Last Name: ' + lname);
            console.log('Email: ' + email);
            console.log('Username: ' + username);
            console.log('Password: ' + password);

            return false; // prevent form submission
        }
        </script>
    </body>
</html>
