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
            <h1 class="blackcolor" >Reservations</h1><hr></br>
            <?php if(isset($_SESSION['loggedin'])): ?>
                <?php
                    if(isset($_SESSION['message'])){
                            echo '<div class="success-message alert alert-success" role="alert">' . $_SESSION['message'] . '</div>';
                            unset($_SESSION['message']);
                    }
                ?>
                <?php 
                    if($result->num_rows > 0){
                        //Ausgabe der Reservierungen eines Users
                        while($row = $result->fetch_array(MYSQLI_NUM)){
                            //foreach($row as $r) echo($r);
                            $extras =" / ";
                            if($row[7] == 1 && $row[8] == 1 && $row[9] == 1) $extras = "Frühstück & Haustiere mitnehemen & Parkplatz";
                            if($row[7] == 1 && $row[8] == 1 && $row[9] == 0) $extras = "Frühstück & Haustiere mitnehemen";
                            if($row[7] == 1 && $row[8] == 0 && $row[9] == 1) $extras = "Frühstück & Parkplatz";
                            if($row[7] == 0 && $row[8] == 1 && $row[9] == 1) $extras = "Haustiere mitnehemen & Parkplatz";
                            if($row[7] == 1 && $row[8] == 0 && $row[9] == 0) $extras = "Frühstück";
                            if($row[7] == 0 && $row[8] == 0 && $row[9] == 1) $extras = "Parkplatz";
                            if($row[7] == 0 && $row[8] == 1 && $row[9] == 0) $extras = "Haustiere mitnehemen";
            
                            $actionbtn = "<form method='POST' action='cancel.php'><input type='hidden' id='r_id' name='r_id' value=".$row[0]." /></span><button style='width:10vw; margin-left:2%;' type='submit' class='btn btn-primary' alt='Stonieren'>Stonieren</button></form> <br> <br><form method='POST' action='accept.php'><input type='hidden' id='r_id' name='r_id' value=".$row[0]." /><button  style='width:10vw' type='submit' class='btn btn-primary' alt='Bestätigen'>Bestätigen</button></form>";
                            if($row[2] == 'stoniert') $actionbtn = "<form method='POST' action='cancel.php'><input type='hidden' id='r_id' name='r_id' value=".$row[0]." /><button style='width:10vw; margin-left:2%;' type='submit' class='btn btn-primary' alt='Stonieren'disabled>Stonieren</button></form> <br> <br><form method='POST' action='accept.php'><input type='hidden' id='r_id' name='r_id' value=".$row[0]." /><button  style='width:10vw'  type='submit' class='btn btn-primary' alt='Bestätigen'>Bestätigen</button></form>";
                            if($row[2] == 'bestätigt') $actionbtn = "<form method='POST' action='cancel.php'><input type='hidden' id='r_id' name='r_id' value=".$row[0]." /><button style='width:10vw; margin-left:2%;' type='submit' class='btn btn-primary' alt='Stonieren'>Stonieren</button></form> <br> <br><form method='POST' action='accept.php'><input type='hidden' id='r_id' name='r_id' value=".$row[0]." /><button style='width:10vw' type='submit' class='btn btn-primary' alt='Bestätigen' disabled>Bestätigen</button></form>";
                            
                            if($_SESSION['u_role']=='admin'){
                                //Detailansicht mit Accordion
                                echo("<div class='faq-question-box accordion-item'><p data-bs-toggle='collapse' class='faq-question accordion-button' data-bs-target='#fa".$row[0]."'aria-expanded='true' aria-controls='#fa".$row[0]."'>Nr.: ".$row[0]." - User ".$row[6]." - ".$row[1]." Suite</p></div>");
                                echo("<div id='fa".$row[0]."' class='collapse faq-answer-box'><p>Vom ".$row[4]." bis zum ".$row[5]." </p><p>Preis: ".$row[10]."€</p><p>Status der Reservierung: <strong>".$row[2]."</strong></p><p>Extra Optionen: ".$extras."</p><p>Reserviert am ".$row[3]."</p>");
                                echo("<div class='row mb-3'>".$actionbtn."</div></div><br>");
                            }
                            else{
                                //Ansicht für User
                                echo("<div class ='card'><img class='cardimg' src='img/".check_checkbox($row[1])."'><div class='cardcontainer'> <div class='form-check form-check-inline'>");
                                echo("<h5>".$row[1]." Suite</h5><br><p>Vom ".$row[4]." bis zum ".$row[5]."</p><p>".$row[10]."€</p><br><p>Reserviert am ".$row[3]."</p></div></div></div><br>");
                            }
                        }
                    }else{
                        echo("<p>Wir haben leider keine aktuellen Room Reservations gefunden. Wir freuen uns auf deinen nächsten Besuch bei Serenity Haven!</p> </br>");
                    }
                    ?>
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