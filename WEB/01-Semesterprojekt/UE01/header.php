<?php 
        // Aktuelle Seite in Navbar aktiv anzeigen
        $filename =  basename($_SERVER["SCRIPT_FILENAME"], '.php');
?>
<nav class="top-nav">
        <?php if(isset($_SESSION['loggedin'])): ?>
                <?php if($filename == 'profil'|| $filename == 'editProfil'|| $filename == 'changePw'):?>
                        <a onclick="" href='profil.php'><button type="button" class="glow-on-hover upper-corner active" alt="Profil">Profil</button></a>
                <?php else:?>
                        <a onclick="" href='profil.php'><button type="button" class="glow-on-hover upper-corner" alt="Profil">Profil</button></a>
                <?php endif?>
        <?php else: ?>
                <?php if($filename == 'login'):?>
                        <a onclick="" href='login.php'><button type="button" class="glow-on-hover upper-corner active" alt="Login">Login</button></a>
                <?php else:?>
                        <a onclick="" href='login.php'><button type="button" class="glow-on-hover upper-corner" alt="Login">Login</button></a>
                <?php endif?>

                <?php if($filename == 'register'):?>
                        <a onclick="" href='register.php'><button type="button" class="glow-on-hover upper-corner active" alt="Register">Register</button></a>
                <?php else:?>
                        <a onclick="" href='register.php'><button type="button" class="glow-on-hover upper-corner" alt="Register">Register</button></a>
                <?php endif?>
        <?php endif; ?>
</nav>
 <header>
        <a href="index.php"><img src="img/logo-transparent.png" width="330px"></a>
        <nav>
                <?php if($filename == 'reservation' || $filename == 'booking'|| $filename == 'checkout'):?>
                        <a onclick="" href='reservation.php'><button type="button" class="glow-on-hover active" alt="Reservation">Reservation</button></a>
                <?php else:?>
                        <a onclick="" href='reservation.php'><button type="button" class="glow-on-hover" alt="Reservation">Reservation</button></a>
                <?php endif?>

                <?php if($filename == 'index'):?>
                        <a onclick="" href='index.php'><button type="button" class="glow-on-hover active" alt="Homepage">Homepage</button></a>
                <?php else:?>
                        <a onclick="" href='index.php'><button type="button" class="glow-on-hover" alt="Homepage">Homepage</button></a>
                <?php endif?>

                <?php if($filename == "help"):?>
                        <a onclick="" href='help.php'><button type="button" class="glow-on-hover active" alt="Help/FAQ">Help/FAQs</button></a>
                <?php else:?>
                        <a onclick="" href='help.php'><button type="button" class="glow-on-hover" alt="Help/FAQ">Help/FAQs</button></a>
                <?php endif?>

                <?php if($filename == "impressum"):?>
                        <a onclick="" href='impressum.php'><button type="button" class="glow-on-hover active" alt="Impressum">Impressum</button></a>
                <?php else:?>
                        <a onclick="" href='impressum.php'><button type="button" class="glow-on-hover" alt="Impressum">Impressum</button></a>
                <?php endif?>
        </nav>
</header>
<script>
</script>