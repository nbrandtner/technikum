<?php
// Start the session
session_start();
include 'db_config.php';
//News infos aus der Datenbank holen
$stmt = $mysqli->prepare("SELECT * FROM news ORDER BY n_date desc");
$stmt->execute();
$result = $stmt->get_result();
$stmt->close();
?>
<!DOCTYPE html>
<html lang="en">
    <?php include 'htmlhead.php'; ?>
    <body>   
        <?php include 'header.php'; ?>
        <div class="icon-container">
        <main>
            <h1 class="blackcolor">Welcome to Serenity Haven!</h1>
            <?php if(isset($_SESSION['loggedin']) && $_SESSION['u_role'] == "admin"): ?>
                <hr>
                <br>
                <form enctype="multipart/form-data" method="post" action="index.php">
                    <input type="file" name="fileToUpload"  id="fileToUpload">
                    <input type="text" name="title" id=title placeholder="Titel">
                    <input type="submit" value="Hochladen" name ="submit">
                </form>
                <br>
            <?php endif; ?> 
            <?php
                    if(isset($_SESSION['message'])) {
                         if($_SESSION['message'] == 'Upload successful') {
                            echo '<div class="success-message alert alert-success" role="alert">' . $_SESSION['message'] . '</div>';
                            unset($_SESSION['message']);
                        } else {
                            echo '<div class="error-message alert alert-danger" role="alert">' . $_SESSION['message'] . '</div>';
                            unset($_SESSION['message']);
                            }
                        }
                ?>
            <?php include 'fileupload.php'; ?>
            <hr>

            
            <?php if($result->num_rows > 0):?>
                    <?php 
                    //Ausgabe der News beiträge 
                     while($row = $result->fetch_array(MYSQLI_NUM)){
                        //foreach($row as $r) echo($r);
                        echo("<div class ='card'><img class='cardimg' src='img/".$row[1]."'><div class='cardcontainer'> <div class='form-check form-check-inline'>");
                        echo("<h5>".$row[3]."</h5><br><p>Vom ".$row[2]."</p><br></div></div></div><br>");
                    }
                    ?>
            <?php else: ?>
                    <p>Gerade gibt es noch keine News Beiträge.</p> </br>
            <?php endif; ?>
          
        </main>
        <footer>
            <p>&copy; <?php echo date("Y"); ?> Hotel Website</p>
        </footer>
        <script src="https://code.jquery.com/jquery-3.7.1.js" integrity="sha256-eKhayi8LEQwp4NKxN+CfCh+3qOVUtJn3QNZ0TciWLP4=" crossorigin="anonymous"></script>
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ka7Sk0Gln4gmtz2MlQnikT1wXgYsOg+OMhuP+IlRH9sENBO0LRn5q+8nbTov4+1p" crossorigin="anonymous"></script>
    </body>
</html>