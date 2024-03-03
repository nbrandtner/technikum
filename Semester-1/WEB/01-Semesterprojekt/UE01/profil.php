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
        <?php
          include 'header.php';
        ?>
        <main>
                <div class="row justify-content-center">
                    <div class ='card'>
                        <div class='cardcontainer'>
                            <h1 class="blackcolor">Welcome <?php echo $_SESSION['u_title'] . ' ' . $username; ?>!</h1><hr><br>
                            <p>Deine Role ist : '<?php echo $role; ?>'</p>
                            <p>Dein Username ist : '<?php echo $username; ?>'</p>
                            <p>Hier kannst du die Daten deines Profils einsehen und bearbeiten oder dein Passwort ändern:</p>
                            <button style="max-width:30mv" onclick="window.location.href='editProfil.php'" type="button" class="btn btn-outline-primary" alt="Edit Profile">Edit Profile</button>
                            <button style="maxwidth:30mv" onclick="window.location.href='changePw.php'" type="button" class="btn btn-outline-primary" alt="Change Password">Change Password</button>
                            <?php
                            //if the $role is admin an additional button for the user_list.php should be displayed
                            if ($role == 'admin') {
                                echo '<button style="maxwidth:30mv" onclick="window.location.href=\'user_list.php\'" type="button" class="btn btn-outline-primary" alt="User List">User List</button>';
                            }                                
                            ?>
                            <br><br>
                            <form action="logout.php" method="post"> 
                            <button type="submit" value="Logout" class="btn btn-outline-danger ">Logout</button>
                            </form>
                            <p>Und hier kannst du dich ausloggen:</p> 
                            </div>
                    </div>
                </div>
        </main>
        <footer>
            <p>&copy; <?php echo date("Y"); ?> Hotel Website</p>
        </footer>
        <script src="https://code.jquery.com/jquery-3.7.1.js" integrity="sha256-eKhayi8LEQwp4NKxN+CfCh+3qOVUtJn3QNZ0TciWLP4=" crossorigin="anonymous"></script>
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ka7Sk0Gln4gmtz2MlQnikT1wXgYsOg+OMhuP+IlRH9sENBO0LRn5q+8nbTov4+1p" crossorigin="anonymous"></script>
    </body>
</html>
