SET PASSWORD FOR 'root'@'localhost' = PASSWORD('P@ssword');

CREATE DATABASE wordpress;

GRANT ALL PRIVILEGES ON wordpress.* TO 'wpuser'@'localhost' IDENTIFIED BY 'P@ssword';

DROP DATABASE test;