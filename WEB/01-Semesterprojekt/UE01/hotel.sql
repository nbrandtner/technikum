-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `mydb` DEFAULT CHARACTER SET utf8 ;
USE `mydb` ;

-- -----------------------------------------------------
-- Table `mydb`.`user`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `mydb`.`user` ;

CREATE TABLE IF NOT EXISTS `mydb`.`user` (
  `u_id` INT NOT NULL AUTO_INCREMENT,
  `u_firstname` VARCHAR(45) NOT NULL,
  `u_lastname` VARCHAR(45) NOT NULL,
  `u_role` VARCHAR(45) NOT NULL,
  `u_pw` VARCHAR(60) NULL,
  `u_gender` VARCHAR(45) NULL,
  `u_status` TINYINT NULL,
  `u_title` VARCHAR(45) NULL,
  `u_email` VARCHAR(45) NULL,
  `u_username` VARCHAR(45) NULL,
  PRIMARY KEY (`u_id`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`news`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `mydb`.`news` ;

CREATE TABLE IF NOT EXISTS `mydb`.`news` (
  `n_id` INT NOT NULL AUTO_INCREMENT,
  `n_path` VARCHAR(45) NOT NULL,
  `n_date` DATETIME NOT NULL,
  `n_title` VARCHAR(45) NULL,
  `n_text` VARCHAR(45) NULL,
  PRIMARY KEY (`n_id`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`reservation`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `mydb`.`reservation` ;

CREATE TABLE IF NOT EXISTS `mydb`.`reservation` (
  `r_id` INT NOT NULL AUTO_INCREMENT,
  `r_room` VARCHAR(45) NULL,
  `r_status` VARCHAR(45) NULL,
  `r_booked` DATETIME NULL,
  `r_from` DATETIME NULL,
  `r_to` DATETIME NULL,
  `r_user` INT NOT NULL,
  `r_food` TINYINT NULL,
  `r_pet` TINYINT NULL,
  `r_parking` TINYINT NULL,
  `r_price` INT NULL,
  PRIMARY KEY (`r_id`),
  INDEX `fk_reservation_user_idx` (`r_user` ASC),
  CONSTRAINT `fk_reservation_user`
    FOREIGN KEY (`r_user`)
    REFERENCES `mydb`.`user` (`u_id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
