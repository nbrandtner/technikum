<?php
session_start();
include 'db_config.php';  // Include your database connection file

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $username = $_POST['username'];
    $password = $_POST['password'];

    // Assuming your database table is named 'user'
    $query = "SELECT * FROM user WHERE u_username = ? AND u_pw = ?";
    
    // Use prepared statements to prevent SQL injection
    $stmt = $mysqli->prepare($query);
    $stmt->bind_param("ss", $username, $password);
    $stmt->execute();
    $result = $stmt->get_result();

    if ($result->num_rows == 1) {
        // Credentials are correct, set the session variables
        $user = $result->fetch_assoc();
        $_SESSION['loggedin'] = true;
        $_SESSION['u_username'] = $user['u_username'];
        $_SESSION['u_pw'] = $user['u_pw'];
        $_SESSION['u_role'] = $user['u_role'];
    
        $stmt->close();
        $mysqli->close();
    
        // Redirect to a new page based on the user role
        if ($_SESSION["u_role"] == "user") {
            header("Location: index.php");
            exit;
        } else if ($_SESSION["u_role"] == "admin") {
            header("Location: index.php");
            exit;
        }
    } else {
        // Credentials are incorrect, show an error message
        $_SESSION['message'] = 'Login failed';
    }

    if (isset($_SESSION["loggedin"]) && isset($_SESSION["username"]) && isset($_SESSION["role"])) {
        // Redirect to a new page based on the user role
        if ($_SESSION["role"] == "user") {
            header("Location: index.php");
        } else if ($_SESSION["role"] == "admin") {
            header("Location: index.php");
        }
        exit;
    }
}

?>
<!DOCTYPE html>
<html lang="en">
    <?php include 'htmlhead.php'; ?>
    <body>
        <nav class="top-nav">
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
                                    <label style="color:white;" for="username">Username</label>
                                    <input type="text" class="form-control" id="username" name="username" placeholder="Username" required>
                                </div>
                                <div class="form-group">
                                    <label style="color:white;" for="password">Password</label>
                                    <input type="password" class="form-control" id="password" name="password" placeholder="Password" required>
                                </div>
                                <button type="submit" name="submit" class="btn btn-primary">Login</button><br>
                                <button onclick="window.location.href='index.php'" type="button" href="index.php"class="btn btn-primary">Close</button>
                            </form>
                            <!-- Display error message if set -->
                            <?php
                            if (isset($_SESSION['message'])) {
                                echo '<div class="error-message alert alert-danger" role="alert">' . $_SESSION['message'] . '</div>';
                                unset($_SESSION['message']); // Clear the message after displaying
                            }
                            ?>
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
