CREATE DATABASE  IF NOT EXISTS `saintheque` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */;
USE `saintheque`;
-- MySQL dump 10.13  Distrib 8.0.13, for Win64 (x86_64)
--
-- Host: localhost    Database: saintheque
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
  `id_adherents` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT 'Clé primaire de l''adherent.',
  `nom` varchar(45) NOT NULL,
  `prenom` varchar(45) NOT NULL,
  `mail` varchar(45) NOT NULL,
  `mdp` varchar(45) NOT NULL,
  `role` varchar(45) NOT NULL DEFAULT 'client_saintheque',
  `nbr_ouvrages_max` int(10) unsigned NOT NULL DEFAULT '5',
  `adresse` varchar(255) NOT NULL,
  `score` int(10) unsigned NOT NULL DEFAULT '100',
  PRIMARY KEY (`id_adherents`),
  UNIQUE KEY `idadhérents_UNIQUE` (`id_adherents`)
) ENGINE=InnoDB AUTO_INCREMENT=14 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `adherents`
--

LOCK TABLES `adherents` WRITE;
/*!40000 ALTER TABLE `adherents` DISABLE KEYS */;
INSERT INTO `adherents` VALUES (1,'Philippe','Edouard','edouard.philippe@mail.fr','PEDD','client_saintheque',0,'5 rue du Nord, 42000 Saint-Etienne, France',100),(2,'Gonga','Jérôme','jerome.gonga@mail.fr','GJEA','client_saintheque',5,'2 avenue Duroy, 42000 Saint-Etienne, France',200),(3,'Davirdcwuk','Puim','puim.davirdcwuk@mail.fr','DPUK','client_saintheque',0,'86 rue de Meil, 42000 Saint-Etienne, France',100),(4,'Euuaaeoi','Xoiaua','xoiaua.euuaaeoi@mail.fr','EXOI','bibliothecaire_saintheque',5,'35 rue de Mieuo, 42000 Saint-Etienne, France',100),(5,'Padeq','Qefif','qefif.padeq@mail.fr','PQEQ','bibliothecaire_saintheque',5,'70 rue de Eerar, 42000 Saint-Etienne, France',100),(6,'Kehi','Dahof','dahof.kehi@mail.fr','KDAI','bibliothecaire_saintheque',0,'72 rue de Tobo, 42000 Saint-Etienne, France',100),(7,'Iiloje','Demi','demi.iiloje@mail.fr','IDEE','bibliothecaire_saintheque',0,'81 rue de Dote, 42000 Saint-Etienne, France',100),(8,'Uiwamal','Vicec','vicec.uiwamal@mail.fr','UVIL','client_saintheque',0,'62 rue de Voro, 42000 Saint-Etienne, France',100),(9,'Yivizad','Joruj','joruj.yivizad@mail.fr','YJOD','bibliothecaire_saintheque',0,'95 rue de Hira, 42000 Saint-Etienne, France',100),(10,'Niqiwis','Gihece','gihece.niqiwis@mail.fr','NGIS','bibliothecaire_saintheque',0,'45 rue de Zefok, 42000 Saint-Etienne, France',100),(11,'Cuviseri','Xutodi','xutodi.cuviseri@mail.fr','CXUI','bibliothecaire_saintheque',0,'27 rue de Xuw, 42000 Saint-Etienne, France',100),(12,'Jaco','Pefuq','pefuq.jaco@mail.fr','JPEO','bibliothecaire_saintheque',0,'26 rue de Wik, 42000 Saint-Etienne, France',100),(13,'Zisom','Bexoji','bexoji.zisom@mail.fr','ZBEM','client_saintheque',0,'40 rue de Wug, 42000 Saint-Etienne, France',100);
/*!40000 ALTER TABLE `adherents` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `auteur`
--

DROP TABLE IF EXISTS `auteur`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `auteur` (
  `id_auteur` int(11) NOT NULL AUTO_INCREMENT,
  `nom` varchar(45) NOT NULL,
  `prenom` varchar(45) DEFAULT NULL,
  `date_naissance` date NOT NULL,
  `date_mort` date DEFAULT NULL,
  `biographie` varchar(255) DEFAULT NULL,
  `id_genre` int(11) unsigned NOT NULL,
  PRIMARY KEY (`id_auteur`),
  KEY `genre_idx` (`id_genre`),
  KEY `genre_idxx` (`id_genre`),
  KEY `add_genre_idx` (`id_genre`),
  CONSTRAINT `add_genre` FOREIGN KEY (`id_genre`) REFERENCES `genre` (`id_genre`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `auteur`
--

LOCK TABLES `auteur` WRITE;
/*!40000 ALTER TABLE `auteur` DISABLE KEYS */;
INSERT INTO `auteur` VALUES (1,'Camus','Albert','1913-11-07','1960-01-04',NULL,1);
/*!40000 ALTER TABLE `auteur` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `emprunts`
--

DROP TABLE IF EXISTS `emprunts`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `emprunts` (
  `id_emprunts` int(11) NOT NULL AUTO_INCREMENT,
  `id_adherent` int(11) unsigned NOT NULL,
  `id_exemplaire` int(11) unsigned NOT NULL,
  `date_emprunt` date NOT NULL,
  `etat` varchar(45) NOT NULL DEFAULT 'ok',
  `rendu` tinyint(4) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id_emprunts`),
  UNIQUE KEY `id_emprunts_UNIQUE` (`id_emprunts`),
  KEY `add_adherent_idx` (`id_adherent`),
  KEY `add_exemplaire_idx` (`id_exemplaire`),
  CONSTRAINT `add_adherent` FOREIGN KEY (`id_adherent`) REFERENCES `adherents` (`id_adherents`),
  CONSTRAINT `add_exemplaire` FOREIGN KEY (`id_exemplaire`) REFERENCES `exemplaires` (`id_exemplaire`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `emprunts`
--

LOCK TABLES `emprunts` WRITE;
/*!40000 ALTER TABLE `emprunts` DISABLE KEYS */;
INSERT INTO `emprunts` VALUES (1,5,1,'2018-03-09','ok',1),(2,7,3,'2019-01-11','ok',1),(3,2,4,'2019-01-15','ok',0),(4,6,2,'2018-12-30','ok',0);
/*!40000 ALTER TABLE `emprunts` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `exemplaires`
--

DROP TABLE IF EXISTS `exemplaires`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `exemplaires` (
  `id_exemplaire` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `date_reception` date NOT NULL,
  `id_mediatheque` int(11) NOT NULL,
  `id_ouvrage` int(11) unsigned NOT NULL,
  PRIMARY KEY (`id_exemplaire`),
  KEY `mediatheque_idx` (`id_mediatheque`),
  KEY `ouvrage_idx` (`id_ouvrage`),
  CONSTRAINT `mediatheque` FOREIGN KEY (`id_mediatheque`) REFERENCES `mediatheques` (`id_mediateques`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  CONSTRAINT `ouvrage` FOREIGN KEY (`id_ouvrage`) REFERENCES `ouvrage` (`id_ouvrage`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `exemplaires`
--

LOCK TABLES `exemplaires` WRITE;
/*!40000 ALTER TABLE `exemplaires` DISABLE KEYS */;
INSERT INTO `exemplaires` VALUES (1,'2017-05-03',1,1),(2,'2018-10-06',1,1),(3,'2018-10-06',1,1),(4,'2019-01-02',2,1),(5,'2019-01-02',2,1);
/*!40000 ALTER TABLE `exemplaires` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `genre`
--

DROP TABLE IF EXISTS `genre`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `genre` (
  `id_genre` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `intitule` varchar(45) NOT NULL,
  `description` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id_genre`),
  UNIQUE KEY `intitulé_UNIQUE` (`intitule`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `genre`
--

LOCK TABLES `genre` WRITE;
/*!40000 ALTER TABLE `genre` DISABLE KEYS */;
INSERT INTO `genre` VALUES (1,'Roman',NULL),(2,'Poème',NULL),(3,'Pièce de théâtre',NULL),(4,'Comédie',NULL),(5,'Chanson',NULL),(6,'Tragédie',NULL),(7,'Film',NULL),(8,'Série',NULL),(9,'Musique',NULL),(10,'Court-métrage',NULL),(11,'Texte',NULL);
/*!40000 ALTER TABLE `genre` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `mediatheques`
--

DROP TABLE IF EXISTS `mediatheques`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `mediatheques` (
  `id_mediateques` int(11) NOT NULL AUTO_INCREMENT COMMENT 'Clé primaire des médiatheque',
  `adresse` varchar(45) NOT NULL COMMENT 'format : numéro rue code_postale ville',
  `telephone` varchar(10) NOT NULL COMMENT 'numéro sans 04XXXXXXXX',
  `id_responsable` int(11) unsigned NOT NULL COMMENT 'couple nom/prénom',
  PRIMARY KEY (`id_mediateques`),
  UNIQUE KEY `adresse_UNIQUE` (`adresse`),
  UNIQUE KEY `telephone_UNIQUE` (`telephone`),
  KEY `respo_idx` (`id_responsable`),
  CONSTRAINT `respo` FOREIGN KEY (`id_responsable`) REFERENCES `adherents` (`id_adherents`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8 COMMENT='table de toutes les mediateques de saint-etienne';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `mediatheques`
--

LOCK TABLES `mediatheques` WRITE;
/*!40000 ALTER TABLE `mediatheques` DISABLE KEYS */;
INSERT INTO `mediatheques` VALUES (1,'59 avenue Toral, 42000 Saint-Etienne, France','0477707273',2),(2,'12 rue du Veau, 42000 Saint-Etienne, France','0477808182',9);
/*!40000 ALTER TABLE `mediatheques` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ouvrage`
--

DROP TABLE IF EXISTS `ouvrage`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `ouvrage` (
  `id_ouvrage` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `titre` varchar(255) NOT NULL,
  `id_genre` int(11) unsigned NOT NULL,
  `id_auteur` int(11) NOT NULL,
  `date_parution` date DEFAULT NULL,
  `duree` int(11) DEFAULT NULL COMMENT 'donnée en minutes',
  `id_type_media` int(11) NOT NULL,
  `resume` text,
  PRIMARY KEY (`id_ouvrage`),
  UNIQUE KEY `idouvrage_UNIQUE` (`id_ouvrage`),
  KEY `auteur_idx` (`id_auteur`),
  KEY `genre_idx` (`id_genre`),
  KEY `type_media_idx` (`id_type_media`),
  CONSTRAINT `auteur` FOREIGN KEY (`id_auteur`) REFERENCES `auteur` (`id_auteur`),
  CONSTRAINT `genre` FOREIGN KEY (`id_genre`) REFERENCES `genre` (`id_genre`),
  CONSTRAINT `type_media` FOREIGN KEY (`id_type_media`) REFERENCES `type_media` (`id_type_media`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ouvrage`
--

LOCK TABLES `ouvrage` WRITE;
/*!40000 ALTER TABLE `ouvrage` DISABLE KEYS */;
INSERT INTO `ouvrage` VALUES (1,'Les Justes',3,1,'1949-12-15',NULL,1,NULL);
/*!40000 ALTER TABLE `ouvrage` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `type_media`
--

DROP TABLE IF EXISTS `type_media`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `type_media` (
  `id_type_media` int(11) NOT NULL AUTO_INCREMENT,
  `intitule` varchar(45) NOT NULL,
  `description` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id_type_media`)
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `type_media`
--

LOCK TABLES `type_media` WRITE;
/*!40000 ALTER TABLE `type_media` DISABLE KEYS */;
INSERT INTO `type_media` VALUES (1,'Livre',NULL),(2,'CD',NULL),(3,'DVD',NULL),(4,'Partition',NULL),(5,'Audio',NULL),(6,'USB',NULL),(7,'THS',NULL),(8,'KSET',NULL),(9,'Catalogue',NULL);
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

-- Dump completed on 2019-01-25 23:50:26
