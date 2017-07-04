CREATE TABLE "admin" (`username`	TEXT NOT NULL UNIQUE,`password`	TEXT NOT NULL,`message`	TEXT NOT NULL)
CREATE TABLE `buddies` (`buddyId`	INTEGER NOT NULL,`convId`	INTEGER NOT NULL,FOREIGN KEY(`buddyId`) REFERENCES users(id),FOREIGN KEY(`convId`) REFERENCES conversations(id))
CREATE TABLE "conversations" (`id`	INTEGER PRIMARY KEY AUTOINCREMENT,`name`	TEXT,`date`	TEXT)
CREATE TABLE "groups" (`id1`	INTEGER NOT NULL,`type`	TEXT NOT NULL,`id2`	INTEGER NOT NULL,FOREIGN KEY(`id1`) REFERENCES users ( id ),FOREIGN KEY(`id2`) REFERENCES users ( id ))
CREATE TABLE `messages` (`convId`	INTEGER NOT NULL,`userId`	INTEGER NOT NULL,`message`	TEXT NOT NULL,FOREIGN KEY(`convId`) REFERENCES conversations(id),FOREIGN KEY(`userId`) REFERENCES users(id))
CREATE TABLE "profiles" (`id`	INTEGER NOT NULL UNIQUE,`name`	TEXT,`surname`	TEXT,`age`	NUMERIC,`words`	TEXT,`type`	TEXT,FOREIGN KEY(`id`) REFERENCES users ( `id` ))
CREATE TABLE "requests" (`id1`	INTEGER NOT NULL,`groupType`	TEXT NOT NULL,`id2`	INTEGER NOT NULL,FOREIGN KEY(`id1`) REFERENCES users ( id ),FOREIGN KEY(`id2`) REFERENCES users ( id ))
CREATE TABLE "users" (`id`	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,`username`	TEXT NOT NULL UNIQUE,`password`	TEXT NOT NULL,`type`	TEXT NOT NULL)
CREATE UNIQUE INDEX uxBuddies ON buddies(buddyId,convId)
CREATE UNIQUE INDEX uxGroups ON groups(id1,type,id2)
CREATE UNIQUE INDEX uxRequests ON requests(id1,groupType,id2)
CREATE TRIGGER doubleDeleteGroup AFTER DELETE ON groups BEGIN DELETE FROM groups WHERE id1=OLD.id2 AND type=OLD.type AND id2=OLD.id1;END
CREATE TRIGGER doubleInsertGroup AFTER INSERT ON groups BEGIN INSERT INTO groups VALUES( NEW.id2,NEW.type,NEW.id1);END
CREATE TRIGGER userDelete AFTER DELETE ON users BEGIN DELETE FROM groups WHERE id1=OLD.id;DELETE FROM posts WHERE id=OLD.id;DELETE FROM profiles WHERE id=OLD.id;DELETE FROM requests WHERE id1=OLD.id;END
INSERT INTO users (username,password,type) VALUES("admin","admin","admin")
