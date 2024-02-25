<?php
session_start();
    include 'db_config.php';
    $r_id = $_POST['r_id'];
    // Database conection reservation accepten
    $stmt = $mysqli->prepare("UPDATE reservation SET r_status = 'bestätigt' WHERE r_id = ?");
    $stmt->bind_param("s", $r_id); 
    $stmt->execute();
    $stmt->close();
    $_SESSION['message'] = 'Bestätigung successful';
    header("Location: reservation.php");
?>