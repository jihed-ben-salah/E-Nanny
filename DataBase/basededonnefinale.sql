--------------------------------------------------------
--  Fichier cr�� - mercredi-mai-05-2021   
--------------------------------------------------------
--------------------------------------------------------
--  DDL for Table ACTIVITE
--------------------------------------------------------

  CREATE TABLE "SOUMAYA"."ACTIVITE" 
   (	"NUMERO" NUMBER, 
	"COURS" VARCHAR2(20 BYTE), 
	"ACTIVITE" VARCHAR2(20 BYTE), 
	"ETAT" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table ACTIVITELOI
--------------------------------------------------------

  CREATE TABLE "SOUMAYA"."ACTIVITELOI" 
   (	"ID" NUMBER, 
	"NOM" VARCHAR2(20 BYTE), 
	"PRENOM" VARCHAR2(20 BYTE), 
	"ADRESSE" VARCHAR2(20 BYTE), 
	"PRIX" NUMBER, 
	"TELEPHONE" NUMBER
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table COMMANDE
--------------------------------------------------------

  CREATE TABLE "SOUMAYA"."COMMANDE" 
   (	"ID_COMMANDE" NUMBER, 
	"ID_FOURNISSEUR" NUMBER, 
	"ID_PRODUIT" NUMBER, 
	"MONTANT" NUMBER, 
	"ADRESSE" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table COMPTE
--------------------------------------------------------

  CREATE TABLE "SOUMAYA"."COMPTE" 
   (	"IDC" NUMBER, 
	"LOGIN" VARCHAR2(20 BYTE), 
	"MDP" VARCHAR2(20 BYTE), 
	"ENFANT" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table COURS
--------------------------------------------------------

  CREATE TABLE "SOUMAYA"."COURS" 
   (	"NOMC" VARCHAR2(20 BYTE), 
	"NOME" VARCHAR2(20 BYTE), 
	"HEURED" VARCHAR2(20 BYTE), 
	"HEUREF" VARCHAR2(20 BYTE), 
	"EMAIL" VARCHAR2(20 BYTE), 
	"NUMERO" NUMBER
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table DEVOIRS
--------------------------------------------------------

  CREATE TABLE "SOUMAYA"."DEVOIRS" 
   (	"NOMD" VARCHAR2(20 BYTE), 
	"REFDEV" NUMBER, 
	"NOMC" VARCHAR2(20 BYTE), 
	"DEADLINE" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table ENFANT
--------------------------------------------------------

  CREATE TABLE "SOUMAYA"."ENFANT" 
   (	"ID" NUMBER, 
	"NOM" VARCHAR2(20 BYTE), 
	"PRENOM" VARCHAR2(20 BYTE), 
	"ADRESSE" VARCHAR2(20 BYTE), 
	"AGE" NUMBER, 
	"POIDS" NUMBER, 
	"TAILLE" NUMBER, 
	"MALADIE" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table FOURNISSEUR
--------------------------------------------------------

  CREATE TABLE "SOUMAYA"."FOURNISSEUR" 
   (	"ID" NUMBER, 
	"NOM" VARCHAR2(20 BYTE), 
	"MARQUE" VARCHAR2(20 BYTE), 
	"ADRESSE" VARCHAR2(20 BYTE), 
	"NUMERO" NUMBER
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table MOTCLE
--------------------------------------------------------

  CREATE TABLE "SOUMAYA"."MOTCLE" 
   (	"ID" NUMBER, 
	"SITE" VARCHAR2(500 BYTE), 
	"AGE" NUMBER
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table PERSONNE
--------------------------------------------------------

  CREATE TABLE "SOUMAYA"."PERSONNE" 
   (	"IDENTIFIANT" NUMBER(*,0), 
	"NOM" VARCHAR2(20 BYTE), 
	"PRENOM" VARCHAR2(20 BYTE), 
	"ADRESSE" VARCHAR2(20 BYTE), 
	"EMAIL" VARCHAR2(80 BYTE), 
	"METIER" VARCHAR2(80 BYTE), 
	"NUM_TEL" NUMBER(*,0), 
	"PRIX_HEURE" NUMBER(*,0)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table PRODUIT
--------------------------------------------------------

  CREATE TABLE "SOUMAYA"."PRODUIT" 
   (	"ID_PRODUIT" NUMBER(*,0), 
	"FOURNISSEUR" NUMBER, 
	"NOM" VARCHAR2(20 BYTE), 
	"PRIX" NUMBER
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table RECLAMATION
--------------------------------------------------------

  CREATE TABLE "SOUMAYA"."RECLAMATION" 
   (	"IDENTIFIANT" NUMBER, 
	"MAIL_DESTINATAIRE" VARCHAR2(50 BYTE), 
	"SUJET" VARCHAR2(50 BYTE), 
	"MESSAGE" VARCHAR2(1000 BYTE), 
	"PERSONNE_AIDE" NUMBER
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table RENDEZVOUS
--------------------------------------------------------

  CREATE TABLE "SOUMAYA"."RENDEZVOUS" 
   (	"ID_RDV" NUMBER, 
	"ID_ACTIVITE2" NUMBER, 
	"NOM" VARCHAR2(20 BYTE), 
	"PRENOM" VARCHAR2(20 BYTE), 
	"EMAIL" VARCHAR2(20 BYTE), 
	"PRO_RDV" VARCHAR2(20 BYTE), 
	"HEURE" VARCHAR2(20 BYTE), 
	"DATE_RDV" VARCHAR2(20 BYTE), 
	"TELEPHONE_RDV" NUMBER
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table TIME
--------------------------------------------------------

  CREATE TABLE "SOUMAYA"."TIME" 
   (	"ENFANT" VARCHAR2(20 BYTE), 
	"HOURSTART" NUMBER, 
	"MINUTESTART" NUMBER, 
	"HOUREND" NUMBER, 
	"MINUTEEND" NUMBER
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
REM INSERTING into SOUMAYA.ACTIVITE
SET DEFINE OFF;
REM INSERTING into SOUMAYA.ACTIVITELOI
SET DEFINE OFF;
Insert into SOUMAYA.ACTIVITELOI (ID,NOM,PRENOM,ADRESSE,PRIX,TELEPHONE) values (1,'souma','sou','aaa@aa',22,50607010);
REM INSERTING into SOUMAYA.COMMANDE
SET DEFINE OFF;
Insert into SOUMAYA.COMMANDE (ID_COMMANDE,ID_FOURNISSEUR,ID_PRODUIT,MONTANT,ADRESSE) values (1,1,1,222,'aaaa');
REM INSERTING into SOUMAYA.COMPTE
SET DEFINE OFF;
Insert into SOUMAYA.COMPTE (IDC,LOGIN,MDP,ENFANT) values (1,'fadhel','123','bensassi');
REM INSERTING into SOUMAYA.COURS
SET DEFINE OFF;
Insert into SOUMAYA.COURS (NOMC,NOME,HEURED,HEUREF,EMAIL,NUMERO) values ('math','ma','12:00 AM','1:02 AM','aaa',1);
REM INSERTING into SOUMAYA.DEVOIRS
SET DEFINE OFF;
REM INSERTING into SOUMAYA.ENFANT
SET DEFINE OFF;
Insert into SOUMAYA.ENFANT (ID,NOM,PRENOM,ADRESSE,AGE,POIDS,TAILLE,MALADIE) values (1,'soumayaaaa','bensassi','rien',22,22,22,'aaaa');
Insert into SOUMAYA.ENFANT (ID,NOM,PRENOM,ADRESSE,AGE,POIDS,TAILLE,MALADIE) values (3,'yussef','ilbhim','soumaya',1,10,10,'reseau');
REM INSERTING into SOUMAYA.FOURNISSEUR
SET DEFINE OFF;
Insert into SOUMAYA.FOURNISSEUR (ID,NOM,MARQUE,ADRESSE,NUMERO) values (1,'aaa','aaa','aaa',222);
REM INSERTING into SOUMAYA.MOTCLE
SET DEFINE OFF;
Insert into SOUMAYA.MOTCLE (ID,SITE,AGE) values (3,'aaaa',10);
Insert into SOUMAYA.MOTCLE (ID,SITE,AGE) values (1,'aaaa',4);
Insert into SOUMAYA.MOTCLE (ID,SITE,AGE) values (2,'aaaa',6);
Insert into SOUMAYA.MOTCLE (ID,SITE,AGE) values (4,'aaaa',6);
Insert into SOUMAYA.MOTCLE (ID,SITE,AGE) values (5,'ssss',3);
REM INSERTING into SOUMAYA.PERSONNE
SET DEFINE OFF;
Insert into SOUMAYA.PERSONNE (IDENTIFIANT,NOM,PRENOM,ADRESSE,EMAIL,METIER,NUM_TEL,PRIX_HEURE) values (12,'aaa','aaa','aaa','aa@','medecin',50607010,22);
Insert into SOUMAYA.PERSONNE (IDENTIFIANT,NOM,PRENOM,ADRESSE,EMAIL,METIER,NUM_TEL,PRIX_HEURE) values (1,'soumaya','aaaa','aaaa','soumaya@aa','prof dessin',50607010,22);
Insert into SOUMAYA.PERSONNE (IDENTIFIANT,NOM,PRENOM,ADRESSE,EMAIL,METIER,NUM_TEL,PRIX_HEURE) values (55,'sss','dd','ssss','ss@ss','medecin',50607010,22);
Insert into SOUMAYA.PERSONNE (IDENTIFIANT,NOM,PRENOM,ADRESSE,EMAIL,METIER,NUM_TEL,PRIX_HEURE) values (61,'aa','aaa','aaa','aa@aaa','infirmiere',50607010,22);
Insert into SOUMAYA.PERSONNE (IDENTIFIANT,NOM,PRENOM,ADRESSE,EMAIL,METIER,NUM_TEL,PRIX_HEURE) values (7,'aaa','aaa','aaa','aa@aa','babysitters',50607010,22);
REM INSERTING into SOUMAYA.PRODUIT
SET DEFINE OFF;
Insert into SOUMAYA.PRODUIT (ID_PRODUIT,FOURNISSEUR,NOM,PRIX) values (1,22,'aaa',411);
REM INSERTING into SOUMAYA.RECLAMATION
SET DEFINE OFF;
Insert into SOUMAYA.RECLAMATION (IDENTIFIANT,MAIL_DESTINATAIRE,SUJET,MESSAGE,PERSONNE_AIDE) values (2,'soumaya.bensassi@esprit.tn','probleme','pappapapappaap',2);
Insert into SOUMAYA.RECLAMATION (IDENTIFIANT,MAIL_DESTINATAIRE,SUJET,MESSAGE,PERSONNE_AIDE) values (1,'soumaya.bensassi@esprit.tn','ddd','sssssssssssssssssss',2);
Insert into SOUMAYA.RECLAMATION (IDENTIFIANT,MAIL_DESTINATAIRE,SUJET,MESSAGE,PERSONNE_AIDE) values (4,'soumaya.bensassi@esprit.tn','pro','vvvvvvvvvvvvvvv',2);
Insert into SOUMAYA.RECLAMATION (IDENTIFIANT,MAIL_DESTINATAIRE,SUJET,MESSAGE,PERSONNE_AIDE) values (5,'soumaya.bensassi@esprit.tn','bonjour','aaaaaaaaaaaaaaaa',2);
Insert into SOUMAYA.RECLAMATION (IDENTIFIANT,MAIL_DESTINATAIRE,SUJET,MESSAGE,PERSONNE_AIDE) values (55,'soumaya.bensassi@esprit.tn','probleme','ahahhahahaa',2);
Insert into SOUMAYA.RECLAMATION (IDENTIFIANT,MAIL_DESTINATAIRE,SUJET,MESSAGE,PERSONNE_AIDE) values (66,'soumaya.bensassi@esprit.tn','papap','aaaaaaaaaaaaaaaaaaaa',2);
Insert into SOUMAYA.RECLAMATION (IDENTIFIANT,MAIL_DESTINATAIRE,SUJET,MESSAGE,PERSONNE_AIDE) values (58,'soumaya.bensassi@esprit.tn','qqqq','qqqqqqqqqq',2);
REM INSERTING into SOUMAYA.RENDEZVOUS
SET DEFINE OFF;
REM INSERTING into SOUMAYA.TIME
SET DEFINE OFF;
Insert into SOUMAYA.TIME (ENFANT,HOURSTART,MINUTESTART,HOUREND,MINUTEEND) values ('toto',18,13,18,15);
--------------------------------------------------------
--  DDL for Index ACTIVITE_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "SOUMAYA"."ACTIVITE_PK" ON "SOUMAYA"."ACTIVITE" ("NUMERO") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index ACTIVITELOI_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "SOUMAYA"."ACTIVITELOI_PK" ON "SOUMAYA"."ACTIVITELOI" ("ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index COMMANDE_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "SOUMAYA"."COMMANDE_PK" ON "SOUMAYA"."COMMANDE" ("ID_COMMANDE") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index COURS_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "SOUMAYA"."COURS_PK" ON "SOUMAYA"."COURS" ("NOMC") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index DEVOIRS_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "SOUMAYA"."DEVOIRS_PK" ON "SOUMAYA"."DEVOIRS" ("NOMD") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index ENFANT_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "SOUMAYA"."ENFANT_PK" ON "SOUMAYA"."ENFANT" ("ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index FOURNISSEUR_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "SOUMAYA"."FOURNISSEUR_PK" ON "SOUMAYA"."FOURNISSEUR" ("ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index MOTCLE_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "SOUMAYA"."MOTCLE_PK" ON "SOUMAYA"."MOTCLE" ("ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index PERSONNE_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "SOUMAYA"."PERSONNE_PK" ON "SOUMAYA"."PERSONNE" ("IDENTIFIANT") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index PRODUIT_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "SOUMAYA"."PRODUIT_PK" ON "SOUMAYA"."PRODUIT" ("ID_PRODUIT") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index RECLAMATION_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "SOUMAYA"."RECLAMATION_PK" ON "SOUMAYA"."RECLAMATION" ("IDENTIFIANT") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index RENDEZVOUS_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "SOUMAYA"."RENDEZVOUS_PK" ON "SOUMAYA"."RENDEZVOUS" ("ID_RDV") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index TIME_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "SOUMAYA"."TIME_PK" ON "SOUMAYA"."TIME" ("ENFANT") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  Constraints for Table ACTIVITE
--------------------------------------------------------

  ALTER TABLE "SOUMAYA"."ACTIVITE" ADD CONSTRAINT "ACTIVITE_PK" PRIMARY KEY ("NUMERO")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
 
  ALTER TABLE "SOUMAYA"."ACTIVITE" MODIFY ("NUMERO" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table ACTIVITELOI
--------------------------------------------------------

  ALTER TABLE "SOUMAYA"."ACTIVITELOI" ADD CONSTRAINT "ACTIVITELOI_PK" PRIMARY KEY ("ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
 
  ALTER TABLE "SOUMAYA"."ACTIVITELOI" MODIFY ("ID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table COMMANDE
--------------------------------------------------------

  ALTER TABLE "SOUMAYA"."COMMANDE" ADD CONSTRAINT "COMMANDE_PK" PRIMARY KEY ("ID_COMMANDE")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
 
  ALTER TABLE "SOUMAYA"."COMMANDE" MODIFY ("ID_COMMANDE" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table COURS
--------------------------------------------------------

  ALTER TABLE "SOUMAYA"."COURS" ADD CONSTRAINT "COURS_PK" PRIMARY KEY ("NOMC")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
 
  ALTER TABLE "SOUMAYA"."COURS" MODIFY ("NOMC" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table DEVOIRS
--------------------------------------------------------

  ALTER TABLE "SOUMAYA"."DEVOIRS" ADD CONSTRAINT "DEVOIRS_PK" PRIMARY KEY ("NOMD")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
 
  ALTER TABLE "SOUMAYA"."DEVOIRS" MODIFY ("NOMD" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table ENFANT
--------------------------------------------------------

  ALTER TABLE "SOUMAYA"."ENFANT" ADD CONSTRAINT "ENFANT_PK" PRIMARY KEY ("ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
 
  ALTER TABLE "SOUMAYA"."ENFANT" MODIFY ("ID" NOT NULL ENABLE);
 
  ALTER TABLE "SOUMAYA"."ENFANT" MODIFY ("NOM" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table FOURNISSEUR
--------------------------------------------------------

  ALTER TABLE "SOUMAYA"."FOURNISSEUR" ADD CONSTRAINT "FOURNISSEUR_PK" PRIMARY KEY ("ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
 
  ALTER TABLE "SOUMAYA"."FOURNISSEUR" MODIFY ("ID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table MOTCLE
--------------------------------------------------------

  ALTER TABLE "SOUMAYA"."MOTCLE" ADD CONSTRAINT "MOTCLE_PK" PRIMARY KEY ("ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
 
  ALTER TABLE "SOUMAYA"."MOTCLE" MODIFY ("ID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table PERSONNE
--------------------------------------------------------

  ALTER TABLE "SOUMAYA"."PERSONNE" ADD CONSTRAINT "PERSONNE_PK" PRIMARY KEY ("IDENTIFIANT")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
 
  ALTER TABLE "SOUMAYA"."PERSONNE" MODIFY ("IDENTIFIANT" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table PRODUIT
--------------------------------------------------------

  ALTER TABLE "SOUMAYA"."PRODUIT" ADD CONSTRAINT "PRODUIT_PK" PRIMARY KEY ("ID_PRODUIT")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
 
  ALTER TABLE "SOUMAYA"."PRODUIT" MODIFY ("ID_PRODUIT" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table RECLAMATION
--------------------------------------------------------

  ALTER TABLE "SOUMAYA"."RECLAMATION" ADD CONSTRAINT "RECLAMATION_PK" PRIMARY KEY ("IDENTIFIANT")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
 
  ALTER TABLE "SOUMAYA"."RECLAMATION" MODIFY ("IDENTIFIANT" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table RENDEZVOUS
--------------------------------------------------------

  ALTER TABLE "SOUMAYA"."RENDEZVOUS" ADD CONSTRAINT "RENDEZVOUS_PK" PRIMARY KEY ("ID_RDV")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
 
  ALTER TABLE "SOUMAYA"."RENDEZVOUS" MODIFY ("ID_RDV" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table TIME
--------------------------------------------------------

  ALTER TABLE "SOUMAYA"."TIME" MODIFY ("ENFANT" NOT NULL ENABLE);
 
  ALTER TABLE "SOUMAYA"."TIME" ADD CONSTRAINT "TIME_PK" PRIMARY KEY ("ENFANT")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;