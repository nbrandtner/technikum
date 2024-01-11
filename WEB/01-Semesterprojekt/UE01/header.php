<nav class="top-nav">
        <?php if(isset($_SESSION['loggedin'])): ?>
                <button type="button" onclick="window.location.href='profil.php'" href="profil.php" class="glow-on-hover upper-corner" >Profil</button>
        <?php else: ?>
                <button type="button" onclick="window.location.href='register.php'" href="register.php"class="glow-on-hover upper-corner">Register</button>
                <button type="button" onclick="window.location.href='login.php'" href="login.php"class="glow-on-hover upper-corner">Login</button>
        <?php endif; ?>
</nav>
 <header>
        <a href="index.php"><img src="img/logo-transparent.png" width="330px"></a>
        <nav>
                <button onclick="window.location.href='reservation.php'" type="button" href="reservation.php" class="glow-on-hover" alt="Reservation">Booking</button>              
                <button onclick="window.location.href='index.php'" type="button" href="index.php" class="glow-on-hover" alt="Homepage">Homepage</button>
                <button onclick="window.location.href='help.php'" type="button" href="help.php" class="glow-on-hover" alt="Help/FAQ">Help/FAQs</button>
                <button onclick="window.location.href='impressum.php'" type="button" href="impressum.php" class="glow-on-hover" alt="Impressum">Impressum</button>
                <!-- Weitere Navigationslinks für angemeldete Benutzer -->
                <?php if(isset($_SESSION['loggedin'])): ?>
                        <button onclick="window.location.href='reservation_list.php'" type="button" href="reservation.php" class="glow-on-hover" alt="Reservation">Reservations</button>              
                <?php endif; ?>
        </nav>
</header>    