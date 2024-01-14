<?php

if(isset($_POST["submit"])) {
  $target_dir = "img_uploads/";
  $target_file = $target_dir . basename($_FILES["fileToUpload"]["name"]);
  $uploadOk = 1;
  $imageFileType = strtolower(pathinfo($target_file,PATHINFO_EXTENSION));

  // Check if image file is a actual image or fake image
  if(isset($_POST["submit"])) {
    $check = getimagesize($_FILES["fileToUpload"]["tmp_name"]);
    if($check !== false) {
      echo "File is an image - " . $check["mime"] . ".<br>";
      $uploadOk = 1;
    } else {
      echo "File is not an image.<br>";
      $uploadOk = 0;
    }
  }

  // Check if file already exists
  if (file_exists($target_file)) {
    echo "Sorry, file already exists.<br>";
    $uploadOk = 0;
  }

  /* Check file size
  if ($_FILES["fileToUpload"]["size"] > 500000) {
    echo "Sorry, your file is too large.<br>";
    $uploadOk = 0;
  }*/

  // Allow certain file formats
  if($imageFileType != "jpg"  && $imageFileType != "jpeg") {
    echo "Sorry, only JPG, JPEG files are allowed.<br>";
    $uploadOk = 0;
  }

  // Check if $uploadOk is set to 0 by an error
  if ($uploadOk == 0) {
    echo("Sorry, your file was not uploaded.<br>");

  // if everything is ok, try to upload file
  } else{
    //Resize img to thumbnail size
    $width = 400; 
    $height = 250; 
      
    // Get image dimensions 
    list($width_orig, $height_orig) = getimagesize($_FILES["fileToUpload"]["tmp_name"]); 
      
    // Resample the image 
    $image_p = imagecreatetruecolor($width, $height); 
    $image = imagecreatefromjpeg($_FILES["fileToUpload"]["tmp_name"]); 
    imagecopyresized($image_p, $image, 0, 0, 0, 0, $width, $height, $width_orig, $height_orig);  
      if (imagejpeg($image_p, $target_file,100)) {
      echo "The file ". htmlspecialchars( basename( $_FILES["fileToUpload"]["name"])). " has been uploaded.<br>";
      // Database insert news beiträge
      include 'db_config.php';
      $file = $_FILES["fileToUpload"]["name"];
      $date = date('Y-m-d h:i', time());
      $text = $_POST["text"];
      $title = $_POST["title"];
      $stmt = $mysqli->prepare("INSERT INTO news (n_path, n_date, n_title, n_text) VALUES (?, ?, ?,?)");
      $stmt->bind_param("ssss", $file, $date, $title, $text);
      $stmt->execute();
      $stmt->close();

      $_SESSION['message'] = "Upload successful";
      header("Location: index.php");
    } else {
      echo "Sorry, there was an error uploading your file.<br>";
    }
  }
}
?>
