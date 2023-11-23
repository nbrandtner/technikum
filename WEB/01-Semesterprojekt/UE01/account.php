<?php
session_start();

// Check if the user is logged in
if (!isset($_SESSION['loggedin'])) {
    // User is not logged in. Redirect them to the login page
    header('Location: login.php');
    exit;
}

// User's data for this example
$email = $_SESSION['email'];
$password = $_SESSION['password'];
$role = $_SESSION['role'];
$username = $_SESSION['username'];

// Include the users.php file
include 'users.php';

?>
<!DOCTYPE html>
<html>
    <?php include 'header.php'; ?>

    <body>
        <section class="banner">
            <div class="welcome">
                <a href="index.php"><img src="images/Logo_Dewatermaked.jpg" alt="Logo"></a>
            </div>
        </section>
        <?php include 'navbar.php'; ?>
        <main class="main">
            <div class="about">
                <h2>Welcome <?php echo $username;?>!</h2><br>
                <p>Email: <?php echo $email; ?></p>
                <p>Password: <?php echo $password; ?></p>
                <p>Role: <?php echo $role; ?></p>
                <!-- Add more user data here -->
                <form action="logout.php" method="post">
                    <input type="submit" value="Logout">
                </form>
                <form action="editaccount.php" method="post">
                    <input type="submit" value="Change Password">
                </form>
            </div>
        </main>
        <?php include 'footer.php'; ?>
        <script src="js/bootstrap.min.js"></script>
    </body>  
</html>
