<?php
// Start the session
session_start(); 

//Datenbank download der Resverierungen
include 'db_config.php';
//Admin soll alle Reservierungen sehen
if(isset($_SESSION['loggedin'])){
    if($_SESSION['u_role']=='admin') $stmt = $mysqli->prepare("SELECT * FROM reservation ORDER BY r_booked desc");
    else {
        $stmt = $mysqli->prepare("SELECT * FROM reservation WHERE r_user = ? ORDER BY r_booked desc");
        $stmt->bind_param("s", $_SESSION['u_id']);
    }
    $stmt->execute();
    $result = $stmt->get_result();
    $stmt->close();
}



//Zimmerbildpfad holen
function check_checkbox($data){
    $img = 'deluxe.jpg';
    if($data == "Junior"){
        $img = 'junior-suite.png';
    } 
    elseif($data == "Master"){ 
        $img = 'mastersuite.jpg';
    }
    elseif($data == "Penthouse"){
        $img = 'penthouse-suite.jpg';
    }
    return $img;
}
?>
<!DOCTYPE html>
<html lang="en">
    <?php include 'htmlhead.php'; ?>
    <body>
        <?php
            include 'header.php';
        ?>
        <div class="icon-container">
        <main>
            <?php if(isset($_SESSION['loggedin'])): ?>
                <?php if($_SESSION['u_role']=='user'):?>
                    <button type="submit" class="btn btn-primary" onclick="window.location.href='booking.php'" >Book your room</button><br>
                <?php endif ?>
            <?php endif ?>    
            <h1 class="blackcolor" >Your Reservations</h1><hr></br>
            <?php if(isset($_SESSION['loggedin'])): ?>
                <?php
                    if(isset($_SESSION['message'])) {
                         if($_SESSION['message'] == 'Reservation successful') {
                            echo '<div class="success-message alert alert-success" role="alert">' . $_SESSION['message'] . '</div>';
                            unset($_SESSION['message']);
                        } else {
                            echo '<div class="error-message alert alert-danger" role="alert">' . $_SESSION['message'] . '</div>';
                            unset($_SESSION['message']);
                            }
                        }
                ?>
                <?php if($result->num_rows > 0):?>
                    <?php 
                    //Ausgabe der Reservierungen eines Users
                     while($row = $result->fetch_array(MYSQLI_NUM)){
                        //foreach($row as $r) echo($r);
                        if($_SESSION['u_role']=='admin'){
                            echo("<div class ='card'><div class='cardcontainer'> <div class='form-check form-check-inline'><p>Reserviert am ".$row[3]."</p>");
                            echo("<h5> User ".$row[6]." - ".$row[1]." Suite</h5><br><p>Vom ".$row[4]." bis zum ".$row[5]." - ".$row[10]."€</p></div></div></div><br>"); 
                        }
                        else{
                            echo("<div class ='card'><img class='cardimg' src='img/".check_checkbox($row[1])."'><div class='cardcontainer'> <div class='form-check form-check-inline'>");
                            echo("<h5>".$row[1]." Suite</h5><br><p>Vom ".$row[4]." bis zum ".$row[5]."</p><p>".$row[10]."€</p><br><p>Reserviert am ".$row[3]."</p></div></div></div><br>");
                        }
                    }
                    ?>
                <?php else: ?>
                    <p>Wir haben leider keine aktuellen Room Reservations gefunden. Wir freuen uns auf deinen nächsten Besuch bei Serenity Haven!</p> </br>
                <?php endif; ?>
                <br>
                <hr>
                </br>
            <?php else: ?>
                <p>Du bist nicht <a onclick="window.location.href='login.php'" class="glow-on-hover" >angemeldet</a>. Bitter melde dich an oder <a onclick="window.location.href='register.php'" class="glow-on-hover" >erstelle ein Konto</a> um einen Raum zu reservieren.</p>
            <?php endif; ?>
        </main>
        <footer>
            <p>&copy; <?php echo date("Y"); ?> Hotel Webseite</p>
        </footer>
        <script src="https://code.jquery.com/jquery-3.7.1.js" integrity="sha256-eKhayi8LEQwp4NKxN+CfCh+3qOVUtJn3QNZ0TciWLP4=" crossorigin="anonymous"></script>
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ka7Sk0Gln4gmtz2MlQnikT1wXgYsOg+OMhuP+IlRH9sENBO0LRn5q+8nbTov4+1p" crossorigin="anonymous"></script>
    </body>
</html>