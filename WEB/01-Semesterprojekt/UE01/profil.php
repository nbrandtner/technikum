<?php
session_start();

// Check if the user is logged in
if (!isset($_SESSION['loggedin'])) {
    // User is not logged in. Redirect them to the login page
    header('Location: login.php');
    exit;
}

// User's data for this example
$password = $_SESSION['u_pw'];
$role = $_SESSION['u_role'];
$username = $_SESSION['u_username'];

// Include the users.php file
include 'users.php';

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
                    <div class="col-md-6" style="color:white">
                        <div class="about">
                            <h2>Welcome <?php echo $username;?>!</h2><br>
                            <p>Password: <?php echo $password; ?></p>
                            <p>Role: <?php echo $role; ?></p>
                            <!-- Add more user data here -->
                            <form action="logout.php" method="post">
                                <input type="submit" value="Logout">
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
