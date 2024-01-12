<?php
session_start();
// define variables and set to empty values
$gender = $fname = $lname = $email = $password = $password_repeat = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $gender = test_input($_POST["gender"]);
    $fname = test_input($_POST["fname"]);
    $lname = test_input($_POST["lname"]);
    $email = test_input($_POST["email"]);
    $password = test_input($_POST["password"]);
    $password_repeat = test_input($_POST["password_repeat"]);

    // Check if all fields are filled
    if(empty($fname) || empty($lname) || empty($email) || empty($gender) || empty($password) || empty($password_repeat)) {
        echo "All fields must be filled out";
    } else {
        // Check if passwords match
        if($password != $password_repeat) {
            echo "Passwords do not match";
        } else {
            // Check if email is valid
            if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
                echo "Invalid email format";
            } else {
                // Check if username is unique
                // This requires a connection to your database and a query to check the username
                // This is just a placeholder. Replace it with your actual database query.
                $username_exists = false; // replace this with your actual check
                if($username_exists) {
                    echo "Username already exists";
                } else {
                    echo "Registration successful";
                    // Here you can add the code to insert the new user into your database
                }
            }
        }
    }
}

function test_input($data) {
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
        <nav class="top-nav">
            <button type="button" onclick="window.location.href='register.php'" href="register.php"class="glow-on-hover upper-corner">Register</button>
            <button type="button" onclick="window.location.href='login.php'" href="login.php"class="glow-on-hover upper-corner">Login</button>
        </nav>
        <header>
        <a href="index.php"><img src="img/logo-transparent.png" width="330px"></a>
            <div class="icon-container">
                <main>
                    <div class="row justify-content-center">
                        <div class="col-md-10">
                            <form action="<?php echo $_SERVER["PHP_SELF"];?>" method="post">
                                <h2 style="color:white;">Register</h2>
                                <div class="form-group">
                                <label style="color:white;" class="form-label">Gender:</label> 
                                    <div class="form-check form-check-inline">
                                        <input type="radio" name="gender" id="male" class="form-check-input input" value="male" checked="">
                                        <label style="color:white;" class="form-check-label mr-3" for="male" alt="male">Male</label>
                                    </div>
                                    <div class="form-check form-check-inline">
                                        <input type="radio" name="gender" id="female" class="form-check-input input" value="female">
                                        <label style="color:white;" class="form-check-label mr-3" for="female" alt="female">Female</label>
                                    </div>
                                    <div class="form-check form-check-inline">
                                        <input type="radio" name="gender" id="diverse" class="form-check-input input" value="diverse">
                                        <label style="color:white;" class="form-check-label" for="diverse" alt="diverse">Diverse</label>
                                    </div>
                                </div>
                                <div class="form-group"> 
                                    <input type="text" class="form-control" id="fname" name="fname" placeholder="Firstname" alt="Please enter your firstname" required>
                                    <br>
                                    <input type="text" class="form-control" id="lname" name="lname" placeholder="Surname" alt="Please enter your surname"required>
                                </div><br>
                                <div class="form-group">
                                    <input type="email" class="form-control" id="email" name="email" placeholder="E-Mail" alt="Please enter your E-Mail" required>
                                </div><br>
                                <div class="form-group">
                                    <input type="text" class="form-control" id="username" name="username" placeholder="Username" alt="Please enter your Username" required>
                                </div><br>
                                <div class="form-group">
                                    <input type="password" class="form-control" id="password" name="password" placeholder="Password" alt="Please enter your password" required>
                                </div><br>
                                <div class="form-group">
                                    <input type="password" class="form-control" id="password_repeat" name="password_repeat" placeholder="Confirm Password" alt="Please confirm your password" required>
                                </div>
                                <button type="submit" name="submit" class="btn btn-primary">Registrieren</button><br>
                                <button onclick="window.location.href='index.php'" type="button" href="index.php"class="btn btn-primary">Close</button>
                            </form>
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
