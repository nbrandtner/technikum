<!-- Modal für Anmeldung -->
<?php
if(session_status() === PHP_SESSION_NONE) {
    session_start();
}
if(isset($_POST['submit'])) {
    $user = $_POST['loginUser'];
    $password = $_POST['loginPW'];
    
    // Überprüfung des Passworts
    if ($user == 'test' && $password == 'test') {
        $_SESSION['user'] = $user;
        header('Location: index.php'); // Redirect to the index page
        exit;
    } else {
        $errorMessage = "E-Mail oder Passwort war ungültig<br>";
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
            <img src="img/logo-transparent.png" width="330px">
            <div class="icon-container">
                <main>
                    <div class="row justify-content-center">
                        <div class="col-md-6">
                            <form action="<?php echo $_SERVER["PHP_SELF"];?>" method="post">
                                <h2 style="color:white;">Login</h2>
                                <div class="form-group">
                                    <label style="color:white;" for="loginUser">Username</label>
                                    <input type="text" class="form-control" id="loginUser" name="loginUser" placeholder="Username" required>
                                </div>
                                <div class="form-group">
                                    <label style="color:white;" for="loginPW">Password</label>
                                    <input type="password" class="form-control" id="loginPW" name="loginPW" placeholder="Password" required>
                                </div>
                                <button type="submit" name="submit" class="btn btn-primary">Login</button>
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
