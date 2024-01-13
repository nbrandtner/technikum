-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jan 13, 2024 at 12:54 AM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `mydb`
--
CREATE DATABASE IF NOT EXISTS `mydb` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;
USE `mydb`;

-- --------------------------------------------------------

--
-- Table structure for table `news`
--

DROP TABLE IF EXISTS `news`;
CREATE TABLE `news` (
  `n_id` int(11) NOT NULL,
  `n_path` varchar(45) NOT NULL,
  `n_date` datetime NOT NULL,
  `n_title` varchar(45) DEFAULT NULL,
  `n_text` varchar(200) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- RELATIONSHIPS FOR TABLE `news`:
--

-- --------------------------------------------------------

--
-- Table structure for table `reservation`
--

DROP TABLE IF EXISTS `reservation`;
CREATE TABLE `reservation` (
  `r_id` int(11) NOT NULL,
  `r_room` varchar(45) DEFAULT NULL,
  `r_status` varchar(45) DEFAULT NULL,
  `r_booked` datetime DEFAULT NULL,
  `r_from` datetime DEFAULT NULL,
  `r_to` datetime DEFAULT NULL,
  `r_user` int(11) NOT NULL,
  `r_food` tinyint(4) DEFAULT NULL,
  `r_pet` tinyint(4) DEFAULT NULL,
  `r_parking` tinyint(4) DEFAULT NULL,
  `r_price` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- RELATIONSHIPS FOR TABLE `reservation`:
--   `r_user`
--       `user` -> `u_id`
--

--
-- Dumping data for table `reservation`
--

INSERT INTO `reservation` (`r_id`, `r_room`, `r_status`, `r_booked`, `r_from`, `r_to`, `r_user`, `r_food`, `r_pet`, `r_parking`, `r_price`) VALUES
(1, 'Junior', 'neu', '2024-01-12 11:41:00', '2024-02-02 00:00:00', '2024-02-08 00:00:00', 3, 1, 0, 0, 1854);

-- --------------------------------------------------------

--
-- Table structure for table `user`
--

DROP TABLE IF EXISTS `user`;
CREATE TABLE `user` (
  `u_id` int(11) NOT NULL,
  `u_firstname` varchar(45) NOT NULL,
  `u_lastname` varchar(45) NOT NULL,
  `u_role` varchar(10) NOT NULL,
  `u_pw` varchar(61) DEFAULT NULL,
  `u_gender` varchar(45) DEFAULT NULL,
  `u_status` tinyint(4) DEFAULT NULL,
  `u_title` varchar(45) DEFAULT NULL,
  `u_email` varchar(45) DEFAULT NULL,
  `u_username` varchar(45) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- RELATIONSHIPS FOR TABLE `user`:
--

--
-- Dumping data for table `user`
--

INSERT INTO `user` (`u_id`, `u_firstname`, `u_lastname`, `u_role`, `u_pw`, `u_gender`, `u_status`, `u_title`, `u_email`, `u_username`) VALUES
(1, 'admin', 'admin', 'admin', '$2y$10$oKGo5XN3i68qI77iQ3xZM.3alePgCmiuZN4NFOQAg9HOzEPf5COGK', 'diverse', 1, 'Mx.', 'admin@admin.com', 'admin'),
(2, 'user', 'user', 'user', '$2y$10$zFhc0qlyE66r7CSu1fwU7.VgEBA8r8xewniiDlMzfNH3kNveJz122', 'diverse', 1, 'Mx.', 'user@user.com', 'user'),
(3, 'Sonja', 'Lechner', 'user', '$2y$10$nJhz03QirtTwrha93d1ZjOSWiVXqUgBphWyJK3kTx4AcMDvu0QIaK', 'diverse', 1, 'Mx.', 'sonja-lechner@gmail.com', 'nomoresonja'),
(8, 'Niklas', 'Brandtner', 'user', '$2y$10$qDkJ2MJbIi4nvdNTmnetSeUWzfMAMdWYcSTsjRj5KmSWbZNziz.iG', 'male', 1, 'Mr.', 'nbrandtner@gmx.at', 'Yukii');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `news`
--
ALTER TABLE `news`
  ADD PRIMARY KEY (`n_id`);

--
-- Indexes for table `reservation`
--
ALTER TABLE `reservation`
  ADD PRIMARY KEY (`r_id`),
  ADD KEY `fk_reservation_user_idx` (`r_user`);

--
-- Indexes for table `user`
--
ALTER TABLE `user`
  ADD PRIMARY KEY (`u_id`),
  ADD UNIQUE KEY `u_username` (`u_username`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `news`
--
ALTER TABLE `news`
  MODIFY `n_id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `reservation`
--
ALTER TABLE `reservation`
  MODIFY `r_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT for table `user`
--
ALTER TABLE `user`
  MODIFY `u_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `reservation`
--
ALTER TABLE `reservation`
  ADD CONSTRAINT `fk_reservation_user` FOREIGN KEY (`r_user`) REFERENCES `user` (`u_id`) ON DELETE NO ACTION ON UPDATE NO ACTION;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
