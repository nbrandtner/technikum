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
                                <?php
                                    if(isset($_SESSION['message'])) {
                                        if($_SESSION['message'] == 'Password changed successfully') {
                                            echo '<div class="success-message alert alert-success" role="alert">' . $_SESSION['message'] . '</div>';
                                            unset($_SESSION['message']);
                                        } else {
                                            echo '<div class="error-message alert alert-danger" role="alert">' . $_SESSION['message'] . '</div>';
                                            unset($_SESSION['message']);
                                        }
                                    }
                                ?>
                                <h2>Welcome <?php echo $_SESSION['u_title'] . ' ' . $username; ?>!</h2>
                                <h6>Role: '<?php echo $role; ?>'</h6>
                                <br>
                                <!-- Add more user data here -->
                                <form action="logout.php" method="post">
                                    <button style="width:15vw" type="submit button" value="Logout" class="glow-on-hover">Logout</button>
                                </form>
                                <br>
                                <button style="width:15vw" onclick="window.location.href='editProfil.php'" type="button" class="glow-on-hover" alt="Edit Profile">Edit Profile</button>
                                <br>
                                <br>
                                <button style="width:15vw" onclick="window.location.href='changePw.php'" type="button" class="glow-on-hover" alt="Change Password">Change Password</button>
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
