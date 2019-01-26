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
) ENGINE=InnoDB AUTO_INCREMENT=32 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `adherents`
--

LOCK TABLES `adherents` WRITE;
/*!40000 ALTER TABLE `adherents` DISABLE KEYS */;
INSERT INTO `adherents` VALUES (1,'Philippe','Edouard','edouard.philippe@mail.fr','PEDD','client_saintheque',0,'5 rue du Nord, 42000 Saint-Etienne, France',100),(2,'Gonga','Jérôme','jerome.gonga@mail.fr','GJEA','client_saintheque',5,'2 avenue Duroy, 42000 Saint-Etienne, France',200),(3,'Davirdcwuk','Puim','puim.davirdcwuk@mail.fr','DPUK','client_saintheque',0,'86 rue de Meil, 42000 Saint-Etienne, France',100),(4,'Euuaaeoi','Xoiaua','xoiaua.euuaaeoi@mail.fr','EXOI','bibliothecaire_saintheque',5,'35 rue de Mieuo, 42000 Saint-Etienne, France',100),(5,'Padeq','Qefif','qefif.padeq@mail.fr','PQEQ','bibliothecaire_saintheque',5,'70 rue de Eerar, 42000 Saint-Etienne, France',100),(6,'Kehi','Dahof','dahof.kehi@mail.fr','KDAI','bibliothecaire_saintheque',0,'72 rue de Tobo, 42000 Saint-Etienne, France',100),(7,'Iiloje','Demi','demi.iiloje@mail.fr','IDEE','bibliothecaire_saintheque',0,'81 rue de Dote, 42000 Saint-Etienne, France',100),(8,'Uiwamal','Vicec','vicec.uiwamal@mail.fr','UVIL','client_saintheque',0,'62 rue de Voro, 42000 Saint-Etienne, France',100),(9,'Yivizad','Joruj','joruj.yivizad@mail.fr','YJOD','bibliothecaire_saintheque',0,'95 rue de Hira, 42000 Saint-Etienne, France',100),(10,'Niqiwis','Gihece','gihece.niqiwis@mail.fr','NGIS','bibliothecaire_saintheque',0,'45 rue de Zefok, 42000 Saint-Etienne, France',100),(11,'Cuviseri','Xutodi','xutodi.cuviseri@mail.fr','CXUI','bibliothecaire_saintheque',0,'27 rue de Xuw, 42000 Saint-Etienne, France',100),(12,'Jaco','Pefuq','pefuq.jaco@mail.fr','JPEO','bibliothecaire_saintheque',0,'26 rue de Wik, 42000 Saint-Etienne, France',100),(13,'Zisom','Bexoji','bexoji.zisom@mail.fr','ZBEM','client_saintheque',0,'40 rue de Wug, 42000 Saint-Etienne, France',100),(14,'Zejoxe','Xevo','xevo.zejoxe@mail.fr','ZXEE','client_saintheque',5,'51 rue de Kofe, 42000 Saint-Etienne, France',100),(15,'Uudu','Yifi','yifi.uudu@mail.fr','UYIU','client_saintheque',3,'8 rue de Zada, 42000 Saint-Etienne, France',100),(16,'Oelizoro','Robi','robi.oelizoro@mail.fr','OROO','admin_saintheque',2,'9 rue de Nob, 42000 Saint-Etienne, France',100),(17,'Kaci','Quriz','quriz.kaci@mail.fr','KQUI','admin_saintheque',3,'77 rue de Koj, 42000 Saint-Etienne, France',100),(18,'Cohabuwu','Yoqaxu','yoqaxu.cohabuwu@mail.fr','CYOU','bibliothecaire_saintheque',2,'68 rue de Fador, 42000 Saint-Etienne, France',100),(19,'Wozigi','Ruku','ruku.wozigi@mail.fr','WRUI','admin_saintheque',5,'70 rue de Maf, 42000 Saint-Etienne, France',100),(20,'Cunamaq','Veko','veko.cunamaq@mail.fr','CVEQ','bibliothecaire_saintheque',3,'64 rue de Auko, 42000 Saint-Etienne, France',100),(21,'Zasub','Zuhenu','zuhenu.zasub@mail.fr','ZZUB','client_saintheque',5,'60 rue de Xelux, 42000 Saint-Etienne, France',100),(22,'Wata','Zuxe','zuxe.wata@mail.fr','WZUA','client_saintheque',3,'80 rue de Wodi, 42000 Saint-Etienne, France',100),(23,'Wijodis','Xitul','xitul.wijodis@mail.fr','WXIS','bibliothecaire_saintheque',2,'77 rue de Xaxu, 42000 Saint-Etienne, France',100),(24,'Audah','Qonaru','qonaru.audah@mail.fr','AQOH','admin_saintheque',1,'78 rue de Cugen, 42000 Saint-Etienne, France',100),(25,'Mijir','Dovi','dovi.mijir@mail.fr','MDOR','client_saintheque',2,'16 rue de Gav, 42000 Saint-Etienne, France',100),(26,'Hakujosa','Wokij','wokij.hakujosa@mail.fr','HWOA','client_saintheque',3,'7 rue de Sol, 42000 saint-Etienne, France',100),(27,'Josu','Yotizi','yotizi.josu@mail.fr','JYOU','bibliothecaire_saintheque',5,'95 rue de Kal, 42000 saint-Etienne, France',100),(28,'Zuresamo','Xako','xako.zuresamo@mail.fr','ZXAO','admin_saintheque',2,'21 rue de Zudij, 42000 saint-Etienne, France',100),(29,'Rabokub','Boqa','boqa.rabokub@mail.fr','RBOB','bibliothecaire_saintheque',1,'75 rue de Gajow, 42000 saint-Etienne, France',100),(30,'Zoku','Aeput','aeput.zoku@mail.fr','ZAEU','client_saintheque',3,'84 rue de Qaqax, 42000 saint-Etienne, France',100),(31,'Maqicafu','Eogo','eogo.maqicafu@mail.fr','MEOU','client_saintheque',2,'60 rue de Pil, 42000 saint-Etienne, France',100);
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
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `auteur`
--

LOCK TABLES `auteur` WRITE;
/*!40000 ALTER TABLE `auteur` DISABLE KEYS */;
INSERT INTO `auteur` VALUES (1,'Camus','Albert','1913-11-07','1960-01-04',NULL,1),(2,'Hugo','Victor','1802-02-26','1885-05-22',NULL,2),(3,'Geffroy','Isabelle','1980-05-01',NULL,'Zaz',5),(4,'Besson','Luc','1959-03-18',NULL,NULL,7);
/*!40000 ALTER TABLE `auteur` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `edition`
--

DROP TABLE IF EXISTS `edition`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `edition` (
  `id_edition` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `nom` varchar(45) NOT NULL,
  `description` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id_edition`),
  UNIQUE KEY `nom_UNIQUE` (`nom`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `edition`
--

LOCK TABLES `edition` WRITE;
/*!40000 ALTER TABLE `edition` DISABLE KEYS */;
INSERT INTO `edition` VALUES (1,'Galimard',NULL),(2,'Larousse',NULL),(3,'Europa Corp.',NULL),(4,'Universal Group.',NULL),(5,'Warner Bros.',NULL),(6,'Urban Comics',NULL),(7,'Marvel Studios',NULL),(8,'DC Comics',NULL);
/*!40000 ALTER TABLE `edition` ENABLE KEYS */;
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
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `emprunts`
--

LOCK TABLES `emprunts` WRITE;
/*!40000 ALTER TABLE `emprunts` DISABLE KEYS */;
INSERT INTO `emprunts` VALUES (1,5,1,'2018-03-09','ok',1),(2,7,3,'2019-01-11','ok',1),(3,2,4,'2019-01-15','ok',0),(4,6,2,'2018-12-30','ok',0),(5,17,7,'2019-01-01','ok',1),(6,14,8,'2017-05-28','ok',1);
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
  `id_edition` int(11) unsigned NOT NULL,
  `date_edition` date NOT NULL,
  PRIMARY KEY (`id_exemplaire`),
  KEY `mediatheque_idx` (`id_mediatheque`),
  KEY `ouvrage_idx` (`id_ouvrage`),
  KEY `edition_idx` (`id_edition`),
  CONSTRAINT `edition` FOREIGN KEY (`id_edition`) REFERENCES `edition` (`id_edition`),
  CONSTRAINT `mediatheque` FOREIGN KEY (`id_mediatheque`) REFERENCES `mediatheques` (`id_mediatheques`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  CONSTRAINT `ouvrage` FOREIGN KEY (`id_ouvrage`) REFERENCES `ouvrage` (`id_ouvrage`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `exemplaires`
--

LOCK TABLES `exemplaires` WRITE;
/*!40000 ALTER TABLE `exemplaires` DISABLE KEYS */;
INSERT INTO `exemplaires` VALUES (1,'2017-05-03',1,1,2,'2012-04-04'),(2,'2018-10-06',1,1,1,'2016-09-17'),(3,'2018-10-06',1,1,1,'2016-09-17'),(4,'2019-01-02',2,1,2,'2018-05-23'),(5,'2019-01-02',2,1,2,'2018-05-23'),(6,'2018-11-28',2,4,3,'2015-07-15'),(7,'2018-12-03',2,2,2,'2014-08-07'),(8,'2016-02-14',2,1,2,'2012-04-04'),(9,'2015-04-29',2,1,2,'2012-04-04');
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
  `id_mediatheques` int(11) NOT NULL AUTO_INCREMENT COMMENT 'Clé primaire des médiatheque',
  `adresse` varchar(45) NOT NULL COMMENT 'format : numéro rue code_postale ville',
  `telephone` varchar(10) NOT NULL COMMENT 'numéro sans 04XXXXXXXX',
  `id_responsable` int(11) unsigned NOT NULL COMMENT 'couple nom/prénom',
  PRIMARY KEY (`id_mediatheques`),
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
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ouvrage`
--

LOCK TABLES `ouvrage` WRITE;
/*!40000 ALTER TABLE `ouvrage` DISABLE KEYS */;
INSERT INTO `ouvrage` VALUES (1,'Les Justes',3,1,'1949-12-15',NULL,1,NULL),(2,'Les Misérables',1,2,'1962-01-01',NULL,1,NULL),(3,'Je veux',5,3,'2010-10-10',NULL,2,NULL),(4,'Lucy',7,4,'2014-08-06',NULL,3,NULL);
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

-- Dump completed on 2019-01-26 14:07:57
