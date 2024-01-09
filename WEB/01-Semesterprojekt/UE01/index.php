<?php
// Start the session
session_start();
?>
<!DOCTYPE html>
<html lang="en">
    <?php include 'htmlhead.php'; ?>
    <body>   
        <?php include 'header.php'; ?>
        <div class="icon-container">
        <main>
            <h1 class="blackcolor">Welcome to Serenity Haven!</h1>
            <?php if(isset($_SESSION['loggedin']) && $_SESSION['role'] == "admin"): ?>
                <hr>
                <br>
                <form enctype="multipart/form-data" method="post" action="index.php">
                    <input type="file" name="fileToUpload"  id="fileToUpload">
                    <input type="submit" value="Hochladen" name ="submit">
                </form>
                <br>
            <?php endif; ?> 
            <?php include 'fileupload.php'; ?>
            <hr>

            
            <?php
            //Schleife zum einfügen der Hochgeladenen Bilder
                $dir = opendir("img_uploads");
                $extensions = array("jpg", "bmp", "gif", "jpeg", "png"); 

                while(($file = readdir($dir)) !== false){
                    if(in_array(pathinfo($file, PATHINFO_EXTENSION), $extensions)){
                    echo "<div class ='card'><img class='cardimg' src='img_uploads/".$file."'><div class='cardcontainer'></div></div><br>";
                    }
                }

            ?>
          
        </main>
        <footer>
            <p>&copy; <?php echo date("Y"); ?> Hotel Website</p>
        </footer>
        <script src="https://code.jquery.com/jquery-3.7.1.js" integrity="sha256-eKhayi8LEQwp4NKxN+CfCh+3qOVUtJn3QNZ0TciWLP4=" crossorigin="anonymous"></script>
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ka7Sk0Gln4gmtz2MlQnikT1wXgYsOg+OMhuP+IlRH9sENBO0LRn5q+8nbTov4+1p" crossorigin="anonymous"></script>
    </body>
</html>