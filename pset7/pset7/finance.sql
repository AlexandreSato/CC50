-- phpMyAdmin SQL Dump
-- version 3.3.2deb1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Nov 14, 2011 at 12:01 AM
-- Server version: 5.1.41
-- PHP Version: 5.3.2-1ubuntu4.10

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `finance`
--
CREATE DATABASE IF NOT EXISTS `finance` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `finance`;

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE IF NOT EXISTS `users` (
  `uid` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `username` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  PRIMARY KEY (`uid`),
  UNIQUE KEY `username` (`username`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=6 ;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`uid`, `username`, `password`) VALUES
(1, 'lemon', 'helloworld'),
(2, 'luke', 'skywalker1'),
(3, 'leia', 'skywalker2'),
(4, 'pskroob', '12345');

-- --------------------------------------------------------

--
-- Table structure for table `custody`
--

CREATE TABLE IF NOT EXISTS `custody` (
  `uids` int(10) unsigned NOT NULL,
  `symbols` varchar(255) NOT NULL,
  `shares` int(255) unsigned NOT NULL,
  PRIMARY KEY (`uids`, `symbols`),
  FOREIGN KEY (`uids`) REFERENCES uses(`uid`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1;

--
-- Dumping data for table `custody`
--

INSERT INTO `custody` (`uids`, `symbols`, `shares`) VALUES
(1, 'GOOG', 1),
(2, 'NFLX', 2),
(3, 'TSLA', 3),
(4, 'VALE', 4);
