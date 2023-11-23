<!-- Modal für Anmeldung -->
<?php
session_start();
include 'users.php';
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $username = $_POST['username'];
    $password = $_POST['password'];

    // Loop through the users array and check if the credentials match
    foreach ($users as $user) {
        if ($username == $user["username"] && $password == $user["password"]) {
            // Credentials are correct, set the session variables
            $_SESSION['loggedin'] = true;
            $_SESSION['username'] = $username;
            $_SESSION['password'] = $password;
            $_SESSION['role'] = $user["role"];
            break;
        }
    }

    // Check if the session variables are set
    if (isset($_SESSION["loggedin"]) && isset($_SESSION["username"]) && isset($_SESSION["role"])) {
        // Redirect to a new page based on the user role
        if ($_SESSION["role"] == "user") {
            header("Location: index.php");
        } else if ($_SESSION["role"] == "admin") {
            header("Location: index.php");
        }
        exit;
    } else {
        // Credentials are incorrect, show an error message
        $_SESSION['message'] = 'Login failed';
    }
}
?>
<!DOCTYPE html>
<html lang="en">
    <?php include 'htmlhead.php'; ?>
    <body>
        <nav class="top-nav">
            <button type="button" onclick="window.location.href='profil.php'" href="profil.php" class="glow-on-hover upper-corner" >Profil</button>
            <button type="button" onclick="window.location.href='register.php'" href="register.php"class="glow-on-hover upper-corner" data-bs-toggle="modal" data-bs-target="#registerModal">Register</button>
            <button type="button" onclick="window.location.href='login.php'" href="login.php"class="glow-on-hover upper-corner" data-bs-toggle="modal" data-bs-target="#loginModal">Login</button>
        </nav>
        <header>
        <a href="index.php"><img src="img/logo-transparent.png" width="330px"></a>
            <div class="icon-container">
                <main>
                    <div class="row justify-content-center">
                        <div class="col-md-6">
                        <form class="credentials" method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
                                <h2 style="color:white;">Login</h2>
                                <div class="form-group">
                                    <label style="color:white;" for="loginUser">Username</label>
                                    <input type="text" class="form-control" id="loginUser" name="loginUser" placeholder="Username" required>
                                </div>
                                <div class="form-group">
                                    <label style="color:white;" for="loginPW">Password</label>
                                    <input type="password" class="form-control" id="loginPW" name="loginPW" placeholder="Password" required>
                                </div>
                                <button type="submit" name="submit" class="btn btn-primary">Login</button><br>
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
    </body>
</html>
