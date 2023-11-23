 <!-- Modal für das Profil -->
 <!-- Modal für Anmeldung -->
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
                                <h2 style="color:white;">Profil</h2>
                                <p style="color:white;">nothing here yet</p><br>
                                <button onclick="window.location.href='index.php'" type="button" href="index.php"class="btn btn-primary">Close</button>
                                <button type="button" class="btn btn-primary">Edit</button>
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
