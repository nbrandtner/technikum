<?php
session_start();
// Database conection reservation stonieren
    include 'db_config.php';
    $r_id = $_POST['r_id'];
    $stmt = $mysqli->prepare("UPDATE reservation SET r_status = 'stoniert' WHERE r_id = ?");
    $stmt->bind_param("s", $r_id); 
    $stmt->execute();
    $stmt->close();
    $_SESSION['message'] = 'Stonierung successful';
    header("Location: reservation.php");
    
?>