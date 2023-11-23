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
            <div class="icon-container">
                <main>
                    <div class="row justify-content-center">
                        <div class="col-md-10">
                            <form action="<?php echo $_SERVER["PHP_SELF"];?>" method="post">
                                <h2 style="color:white;">Register</h2>
                                <div class="form-group">
                                <label style="color:white;" class="form-label">Gender:</label> 
                                    <div class="form-check form-check-inline">
                                        <input type="radio" name="radio" id="male" class="form-check-input input" value="male" checked="">
                                        <label style="color:white; class="form-check-label mr-3" for="male" alt="male">Male</label>
                                    </div>
                                    <div class="form-check form-check-inline">
                                        <input type="radio" name="radio" id="female" class="form-check-input input" value="female">
                                        <label style="color:white; class="form-check-label mr-3" for="female" alt="female">Female</label>
                                    </div>
                                    <div class="form-check form-check-inline">
                                        <input type="radio" name="radio" id="diverse" class="form-check-input input" value="diverse">
                                        <label style="color:white; class="form-check-label" for="diverse" alt="diverse">Diverse</label>
                                    </div>
                                </div>
                                <div class="form-group"> 
                                    <input type="text" class="form-control" id="registerFirstName" name="registerFirstName" placeholder="Firstname" alt="Please enter your firstname" required>
                                    <br>
                                    <input type="text" class="form-control" id="registerLastName" name="registerLastName" placeholder="Surname" alt="Please enter your surname"required>
                                </div><br>
                                <div class="form-group">
                                    <input type="email" class="form-control" id="registerEmail" name="registerEmail" placeholder="E-Mail" alt="Please enter your E-Mail" required>
                                </div><br>
                                <div class="form-group">
                                    <input type="text" class="form-control" id="registerUser" name="registerUser" placeholder="Username" alt="Please enter your Username" required>
                                </div><br>
                                <div class="form-group">
                                    <input type="password" class="form-control" id="registerPassword" name="registerPassword" placeholder="Password" alt="Please enter your password" required>
                                </div><br>
                                <div class="form-group">
                                    <input type="password" class="form-control" id="confirmPassword" name="confirmPassword" placeholder="Confirm Password" alt="Please confirm your password" required>
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
    </body>
</html>
