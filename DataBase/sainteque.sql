CREATE DATABASE  IF NOT EXISTS `sainteque` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */;
USE `sainteque`;
-- MySQL dump 10.13  Distrib 8.0.13, for Win64 (x86_64)
--
-- Host: localhost    Database: sainteque
-- ------------------------------------------------------
-- Server version	8.0.13

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
 SET NAMES utf8 ;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `adherents`
--

DROP TABLE IF EXISTS `adherents`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `adherents` (
  `id_adhérents` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT 'Clé primaire de l''adherent.',
  `nom` varchar(45) NOT NULL,
  `prénom` varchar(45) NOT NULL,
  `mail` varchar(45) NOT NULL,
  `nbr_ouvrages_max` int(10) unsigned NOT NULL DEFAULT '5',
  `adresse` varchar(45) NOT NULL,
  `score` int(10) unsigned NOT NULL DEFAULT '100',
  `mdp` varchar(45) NOT NULL,
  `role` varchar(45) NOT NULL DEFAULT 'Client_Saintheque',
  PRIMARY KEY (`id_adhérents`),
  UNIQUE KEY `idadhérents_UNIQUE` (`id_adhérents`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `adherents`
--

LOCK TABLES `adherents` WRITE;
/*!40000 ALTER TABLE `adherents` DISABLE KEYS */;
INSERT INTO `adherents` VALUES (1,'test','test','test1',10,'test',100,'test1','Admin_Saintheque'),(2,'test','test','test2',10,'test',100,'test2','Bibliothecaire_Saintheque'),(3,'test','test','test3',10,'test',100,'test3','Client_Saintheque');
/*!40000 ALTER TABLE `adherents` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `auteur`
--

DROP TABLE IF EXISTS `auteur`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `auteur` (
  `id_auteur` int(11) NOT NULL,
  `nom` varchar(45) NOT NULL,
  `prenom` varchar(45) DEFAULT NULL,
  `date_naissance` varchar(45) NOT NULL,
  `date_mort` varchar(45) DEFAULT NULL,
  `biographie` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`id_auteur`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `auteur`
--

LOCK TABLES `auteur` WRITE;
/*!40000 ALTER TABLE `auteur` DISABLE KEYS */;
/*!40000 ALTER TABLE `auteur` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `exemplaire`
--

DROP TABLE IF EXISTS `exemplaire`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `exemplaire` (
  `id_exemplaire` int(10) unsigned NOT NULL,
  `id_ouvrage` int(10) unsigned NOT NULL,
  `date_reception` date NOT NULL,
  `id_mediatheque` int(11) NOT NULL,
  PRIMARY KEY (`id_exemplaire`),
  KEY `Ouvrage_idx` (`id_ouvrage`),
  CONSTRAINT `Ouvrage` FOREIGN KEY (`id_ouvrage`) REFERENCES `ouvrage` (`id_ouvrage`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `exemplaire`
--

LOCK TABLES `exemplaire` WRITE;
/*!40000 ALTER TABLE `exemplaire` DISABLE KEYS */;
/*!40000 ALTER TABLE `exemplaire` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `genre`
--

DROP TABLE IF EXISTS `genre`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `genre` (
  `id_genre` varchar(45) NOT NULL,
  `description` varchar(45) NOT NULL,
  PRIMARY KEY (`id_genre`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `genre`
--

LOCK TABLES `genre` WRITE;
/*!40000 ALTER TABLE `genre` DISABLE KEYS */;
/*!40000 ALTER TABLE `genre` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `mediateques`
--

DROP TABLE IF EXISTS `mediateques`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `mediateques` (
  `id_mediateques` int(11) NOT NULL COMMENT 'Clé primaire des médiatheque',
  `adresse` varchar(45) NOT NULL COMMENT 'format : numéro rue code_postale ville',
  `telephone` varchar(10) NOT NULL COMMENT 'numéro sans 04XXXXXXXX',
  `responsable` varchar(45) NOT NULL COMMENT 'couple nom/prénom',
  PRIMARY KEY (`id_mediateques`),
  UNIQUE KEY `adresse_UNIQUE` (`adresse`),
  UNIQUE KEY `telephone_UNIQUE` (`telephone`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='table de toutes les mediateques de saint-etienne';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `mediateques`
--

LOCK TABLES `mediateques` WRITE;
/*!40000 ALTER TABLE `mediateques` DISABLE KEYS */;
/*!40000 ALTER TABLE `mediateques` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ouvrage`
--

DROP TABLE IF EXISTS `ouvrage`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `ouvrage` (
  `id_ouvrage` int(10) unsigned NOT NULL,
  `genre` varchar(45) DEFAULT NULL,
  `auteur` int(11) DEFAULT NULL,
  `date_parution` date DEFAULT NULL,
  `duree` int(11) DEFAULT NULL COMMENT 'donnée en minutes',
  `id_type` varchar(45) NOT NULL,
  PRIMARY KEY (`id_ouvrage`),
  UNIQUE KEY `idouvrage_UNIQUE` (`id_ouvrage`),
  KEY `id_auteur_idx` (`auteur`),
  KEY `Genre_idx` (`genre`),
  KEY `Type_idx` (`id_type`),
  CONSTRAINT `Auteur` FOREIGN KEY (`auteur`) REFERENCES `auteur` (`id_auteur`),
  CONSTRAINT `Genre` FOREIGN KEY (`genre`) REFERENCES `genre` (`id_genre`),
  CONSTRAINT `Type` FOREIGN KEY (`id_type`) REFERENCES `type_media` (`id_type`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ouvrage`
--

LOCK TABLES `ouvrage` WRITE;
/*!40000 ALTER TABLE `ouvrage` DISABLE KEYS */;
/*!40000 ALTER TABLE `ouvrage` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `type_media`
--

DROP TABLE IF EXISTS `type_media`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `type_media` (
  `id_type` varchar(45) NOT NULL,
  `description` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`id_type`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `type_media`
--

LOCK TABLES `type_media` WRITE;
/*!40000 ALTER TABLE `type_media` DISABLE KEYS */;
/*!40000 ALTER TABLE `type_media` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-01-17 15:04:56
