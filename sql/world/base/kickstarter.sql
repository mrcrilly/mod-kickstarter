SET
@Entry := 9000000,
@Model := 28156,
@Name  := "Kickstarter",
@Title := "Getting Started",
@Icon  := "",
@GossipMenu := 0,
@MinLevel := 80,
@MaxLevel := 80,
@Faction  := 35,
@NPCFlag  := 129,
@Scale    := 1.0,
@Rank     := 0,
@Type     := 7,
@TypeFlags := 138936390,
@FlagsExtra := 2,
@AIName     := "SmartAI",
@Script     := "Kickstarter";

DELETE FROM `creature_template` WHERE `entry`=@Entry;
INSERT INTO `creature_template` (`entry`, `modelid1`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `unit_class`, `unit_flags`, `type`, `type_flags`, `InhabitType`, `RegenHealth`, `flags_extra`, `AiName`, `ScriptName`) VALUES
(@Entry, @Model, @Name, @Title, @Icon, @GossipMenu, @MinLevel, @MaxLevel, @Faction, @NPCFlag, 1, 1, @Scale, @Rank, 1, 2, @Type, @TypeFlags, 3, 1, @FlagsExtra, @AIName, @Script);

DELETE FROM `npc_text` WHERE `ID`=@Entry;
INSERT INTO `npc_text` (`ID`, `text0_0`) VALUES (@Entry, 'Why, hello there!');
DELETE FROM `npc_text` WHERE `ID`=@Entry+1;
INSERT INTO `npc_text` (`ID`, `text0_0`) VALUES (@Entry+1, 'What do you need?');



/* Level 80 (item level <174) Greens - Uncomment to enable
-- Equipment
-- Cloth
DELETE FROM `npc_vendor` WHERE `entry`=@Entry;
-- Head
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (38737, 42843, 43850, 43859, 43882);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 38737);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 42843);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 43850);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 43859);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 43882);
-- Shoulders
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (39372, 42842, 43862, 43872);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 39372);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 42842);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 43862);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 43872);
-- Chest
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42792, 42849, 43204, 43881);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 42792);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 42849);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 43204);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 43881);
-- Wrist
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (38736, 38739, 42787, 43855, 43879);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 38736);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 38739);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 42787);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 43855);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 43879);
-- Hands
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (38741, 42790, 42847, 43856);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 38741);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 42790);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 42847);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 43856);
-- Waist
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42785, 42788, 43866);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 42785);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 42788);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 43866);
-- Legs
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42795, 42841, 43863);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 42795);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 42841);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 43863);
-- Feet
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (39814, 42789, 42846, 43839, 43857);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 39814);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 42789);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 42846);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 43839);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 43857);

-- Leather
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+1;
-- Head
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42872, 43840, 43905);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 42872);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 43840);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 43905);
-- Shoulders
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42800, 42805, 42869, 43907);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 42800);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 42805);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 42869);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 43907);
-- Chest
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (39036, 42803, 42870, 43891, 43906, 43912);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 39036);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 42803);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 42870);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 43891);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 43906);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 43912);
-- Wrist
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (39038, 42801, 42806, 42865, 42871, 43913);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 39038);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 42801);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 42806);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 42865);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 42871);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 43913);
-- Hands
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (39040, 39414, 42809, 42866, 43904, 43910);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 39040);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 39414);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 42809);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 42866);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 43904);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 43910);
-- Waist
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42802, 43892, 43909, 43914);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 42802);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 43892);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 43909);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 43914);
-- Legs
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43896, 39380, 39411, 39413);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 43896);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 39380);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 39411);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 39413);
-- Feet
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (39035, 42798, 42804, 42874, 43894, 43908);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 39035);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 42798);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 42804);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 42874);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 43894);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 43908);

-- Mail
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+2;
-- Head
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42810, 42895, 43937, 43978);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 42810);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 42895);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 43937);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 43978);
-- Shoulders
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42820, 42887, 42893, 43830, 43982);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 42820);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 42887);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 42893);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 43830);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 43982);
-- Chest
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42813, 42896, 43935, 43977);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 42813);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 42896);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 43935);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 43977);
-- Wrist
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (39068, 42816, 42888, 42892, 43934, 43980);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 39068);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 42816);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 42888);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 42892);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 43934);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 43980);
-- Hands
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (39070, 39443, 43933, 43976, 43981);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 39070);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 39443);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 43933);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 43976);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 43981);
-- Waist
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (39065, 42814, 42818, 42821, 42889, 43841);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 39065);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 42814);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 42818);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 42821);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 42889);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 43841);
-- Legs
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (39066, 39887, 42817, 42890, 43932, 43979);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 39066);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 39887);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 42817);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 42890);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 43932);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 43979);
-- Feet
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42815, 42891, 43931, 43948);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 42815);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 42891);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 43931);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 43948);

-- Plate Mail
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+3;
-- Head
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (39108, 42829, 42878, 42879, 43846);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 39108);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 42829);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 42878);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 42879);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43846);
-- Shoulders
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (39888, 42834, 42876, 43844, 43941);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 39888);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 42834);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 42876);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43844);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43941);
-- Chest
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (39458, 42827, 42877, 43939, 43945, 43946);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 39458);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 42827);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 42877);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43939);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43945);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43946);
-- Wrist
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (39100, 39104, 42825, 42830, 43942, 43944);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 39100);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 39104);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 42825);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 42830);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43942);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43944);
-- Hands
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42835, 42880, 43842, 43847, 43943);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 42835);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 42880);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43842);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43847);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43943);
-- Waist
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (39471, 42826, 42882, 43831, 43947);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 39471);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 42826);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 42882);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43831);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43947);
-- Legs
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42832, 42881, 43845, 43940);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 42832);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 42881);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43845);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43940);
-- Feet
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (39102, 42833, 42836, 42883, 42884, 43930);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 39102);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 42833);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 42836);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 42883);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 42884);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43930);



-- Accessories
-- Cloaks
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43861, 43889, 43924, 43925);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+4;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 43861);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 43889);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 43924);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 43925);
-- Amulets
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42793, 42808, 43849, 43884);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+5;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42793);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42808);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 43849);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 43884);
-- Rings
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42791, 42812, 42845, 42864, 43874, 43877, 43903, 43926, 39480, 39481, 39482);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+6;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42791);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42812);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42845);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42864);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 43874);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 43877);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 43903);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 43926);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 39480);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 39481);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 39482);
-- Trinkets
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (38763, 38764, 38765, 43829, 43836, 43837, 43838);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+7;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 38763);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 38764);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 38765);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 43829);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 43836);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 43837);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 43838);



-- Weapons
-- Daggers
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (39130, 39133, 42811, 42831, 42848, 42861, 43911, 43915, 43917, 43919);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+8;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 39130);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 39133);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 42811);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 42831);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 42848);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 42861);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43911);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43915);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43917);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43919);
-- Fist Weapons
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42862, 43890);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+9;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 42862);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 43890);
-- One-Handed Axes
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (39136, 43875, 43897, 43898);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+10;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 39136);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 43875);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 43897);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 43898);
-- One-Handed Maces
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (39143, 39144, 42819, 42823, 42868, 43835, 43888, 43916);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+11;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 39143);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 39144);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42819);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42823);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42868);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 43835);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 43888);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 43916);
-- One-Handed Swords
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42786, 42807, 43833, 43923);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+12;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 42786);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 42807);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 43833);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 43923);
-- Polearms
-- UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN ();
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+13;
-- INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+13, 0);
-- Staves
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (39121, 42794, 42828, 42857, 43834, 43858, 43920, 43921, 43927);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+14;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+14, 39121);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+14, 42794);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+14, 42828);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+14, 42857);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+14, 43834);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+14, 43858);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+14, 43920);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+14, 43921);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+14, 43927);
-- Two-Handed Axes
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (39115, 42824, 43899);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+15;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+15, 39115);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+15, 42824);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+15, 43899);
-- Two-Handed Maces
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42859, 43885, 43929);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+16;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+16, 42859);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+16, 43885);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+16, 43929);
-- Two-Handed Swords
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42799, 43832, 43883);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+17;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+17, 42799);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+17, 43832);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+17, 43883);
-- Bows
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (39134, 39135, 43928);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+18;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+18, 39134);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+18, 39135);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+18, 43928);
-- Crossbows
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42858, 43918);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+19;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+19, 42858);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+19, 43918);
-- Guns
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42822);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+20;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+20, 42822);
-- Thrown
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (39138, 42863, 43900);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+21;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+21, 39138);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+21, 42863);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+21, 43900);
-- Wands
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43828, 43873, 43880, 43893);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+22;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+22, 43828);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+22, 43873);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+22, 43880);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+22, 43893);
-- Off-Hand Frills
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42796);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+23;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 42796);
-- Shields
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42860, 43843);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+24;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+24, 42860);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+24, 43843);
*/



/* Level 70 (item level <114) Greens - Uncomment to enable
-- Equipment
-- Cloth
DELETE FROM `npc_vendor` WHERE `entry`=@Entry;
-- Head
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30922, 30931, 30271);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 30922);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 30931);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 30271);
-- Shoulders
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (29954, 30514, 31687);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 29954);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 30514);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 31687);
-- Chest
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (29978, 30518, 30928);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 29978);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 30518);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 30928);
-- Wrist
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30382, 30927, 30265, 30520);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 30382);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 30927);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 30265);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 30520);
-- Hands
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30253, 30930, 31111);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 30253);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 30930);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 31111);
-- Waist
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30331, 30923, 32867, 29771);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 30331);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 30923);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 32867);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 29771);
-- Legs
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30517, 30929);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 30517);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 30929);
-- Feet
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (25793, 30519, 29808, 30284, 30398, 30926);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 25793);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 30519);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 29808);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 30284);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 30398);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 30926);

-- Leather
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+1;
-- Head
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (29979, 30946, 30269, 30362, 31457, 31688);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 29979);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 30946);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 30269);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 30362);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 31457);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 31688);
-- Shoulders
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (25796, 29810, 30938, 29999, 30218, 30262);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 25796);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 29810);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 30938);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 29999);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 30218);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 30262);
-- Chest
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30328, 30379, 30945, 32869, 29967, 31511);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 30328);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 30379);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 30945);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 32869);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 29967);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 31511);
-- Wrist
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30332, 30940, 30399, 29955, 30384, 31793);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 30332);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 30940);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 30399);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 29955);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 30384);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 31793);
-- Hands
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (25795, 30003, 30341, 30937, 32865, 29784, 31313, 31684);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 25795);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 30003);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 30341);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 30937);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 32865);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 29784);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 31313);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 31684);
-- Waist
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30936, 30942, 29772, 30285);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 30936);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 30942);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 29772);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 30285);
-- Legs
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30272, 30290, 30941);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 30272);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 30290);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 30941);
-- Feet
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30335, 31112, 29804, 30266, 30401, 31532);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 30335);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 31112);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 29804);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 30266);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 30401);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 31532);

-- Mail
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+2;
-- Head
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30329, 29773, 30955, 31435);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 30329);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 29773);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 30955);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 31435);
-- Shoulders
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30333, 30952, 32868, 30286, 30295, 31314, 31533);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 30333);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 30952);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 32868);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 30286);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 30295);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 31314);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 31533);
-- Chest
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30255, 30947, 30363, 31514);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 30255);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 30947);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 30363);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 31514);
-- Wrist
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30956, 29785, 29811, 30274);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 30956);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 29785);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 29811);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 30274);
-- Hands
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30336, 29806, 30224, 31515);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 30336);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 29806);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 30224);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 31515);
-- Waist
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (25794, 30342, 31114, 30950, 30001);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 25794);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 30342);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 31114);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 30950);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 30001);
-- Legs
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30957, 32870, 29788, 29968, 31458, 31685, 31689);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 30957);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 32870);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 29788);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 29968);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 31458);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 31685);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 31689);
-- Feet
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30004, 30953, 30958, 30273, 30263);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 30004);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 30953);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 30958);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 30273);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 30263);

-- Plate Mail
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+3;
-- Head
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30337, 30961, 32871, 29791, 29969, 31520);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 30337);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 30961);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 32871);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 29791);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 29969);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 31520);
-- Shoulders
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30005, 30381, 30964, 31115, 30291, 30275, 31436);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 30005);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 30381);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 30964);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 31115);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 30291);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 30275);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 31436);
-- Chest
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30959, 29789, 30270, 30296, 31459, 31686);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 30959);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 29789);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 30270);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 30296);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 31459);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 31686);
-- Wrist
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30352, 30400, 30966, 30225, 30402);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 30352);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 30400);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 30966);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 30225);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 30402);
-- Hands
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (25797, 29812, 30267, 29959, 30264, 31534);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 25797);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 29812);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 30267);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 29959);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 30264);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 31534);
-- Waist
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30254, 30330, 30380, 29807, 31315, 31690);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 30254);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 30330);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 30380);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 29807);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 31315);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 31690);
-- Legs
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (29980, 29774, 30960, 31519);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 29980);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 29774);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 30960);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 31519);
-- Feet
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30334, 30968, 32866, 29786, 30002, 30386);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 30334);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 30968);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 32866);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 29786);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 30002);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 30386);



-- Accessories
-- Cloaks
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30338, 30971, 29792, 29777, 25780);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+4;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 30338);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 30971);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 29792);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 29777);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 25780);
-- Amulets
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30981, 29794, 29775, 30276, 31790, 25914);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+5;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 30981);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 29794);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 29775);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 30276);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 31790);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 25914);
-- Rings
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30006, 30339, 29793, 31523, 31526, 31527, 31528, 31791, 25779, 31820);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+6;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 30006);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 30339);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 29793);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 31523);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 31526);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 31527);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 31528);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 31791);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 25779);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 31820);
-- Trinkets
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30340, 30293, 29776, 25634, 25628, 25633, 31615, 31617);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+7;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 30340);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 30293);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 29776);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 25634);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 25628);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 25633);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 31615);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 31617);



-- Weapons
-- Daggers
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (31703, 25543, 25545, 31446, 31447, 31475, 31476, 31422);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+8;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 31703);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 25543);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 25545);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 31446);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 31447);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 31475);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 31476);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 31422);
-- Fist Weapons
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30277);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+9;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 30277);
-- One-Handed Axes
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30364, 31423);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+10;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 30364);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 31423);
-- One-Handed Maces
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (29787);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+11;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 29787);
-- One-Handed Swords
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30278, 31541, 31448, 31821);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+12;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 30278);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 31541);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 31448);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 31821);
-- Polearms
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30396);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+13;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+13, 30396);
-- Staves
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30522, 31414, 31543, 31700, 25622);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+14;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+14, 30522);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+14, 31414);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+14, 31543);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+14, 31700);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+14, 25622);
-- Two-Handed Axes
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (31542, 31701);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+15;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+15, 31542);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+15, 31701);
-- Two-Handed Maces
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30395);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+16;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+16, 30395);
-- Two-Handed Swords
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30394, 31816);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+17;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+17, 30394);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+17, 31816);
-- Bows
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30226, 31416);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+18;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+18, 30226);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+18, 31416);
-- Crossbows
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30397);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+19;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+19, 30397);
-- Guns
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30279, 25544);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+20;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+20, 30279);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+20, 25544);
-- Thrown
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30227);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+21;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+21, 30227);
-- Wands
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (32872, 30523, 29779, 30252, 31474, 25629, 25632, 31424);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+22;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+22, 32872);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+22, 30523);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+22, 29779);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+22, 30252);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+22, 31474);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+22, 25629);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+22, 25632);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+22, 31424);
-- Off-Hand Frills
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (31699, 31823);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+23;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 31699);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 31823);
-- Shields
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (30986, 31415, 25624);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+24;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+24, 30986);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+24, 31415);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+24, 25624);
*/



-- Gems
-- Meta Gems
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (41285, 41307, 41333, 41335, 41339, 41375, 41376, 41377, 41378, 41379, 41380, 41381, 41382, 41385, 41389, 41395, 41396, 41397, 41398, 41400, 41401, 25890, 25893, 25894, 25895, 25896, 25897, 25898, 25899, 25901, 32409, 32410, 34220, 35501, 35503);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+25;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 41285);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 41307);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 41333);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 41335);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 41339);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 41375);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 41376);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 41377);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 41378);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 41379);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 41380);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 41381);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 41382);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 41385);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 41389);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 41395);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 41396);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 41397);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 41398);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 41400);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 41401);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 25890);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 25893);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 25894);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 25895);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 25896);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 25897);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 25898);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 25899);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 25901);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 32409);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 32410);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 34220);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 35501);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 35503);
-- Red Gems
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (40111, 40112, 40113, 40114, 40115, 40116, 40117, 40118);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+26;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+26, 40111);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+26, 40112);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+26, 40113);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+26, 40114);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+26, 40115);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+26, 40116);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+26, 40117);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+26, 40118);
-- Blue Gems
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (40119, 40120, 40121, 40122);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+27;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+27, 40119);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+27, 40120);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+27, 40121);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+27, 40122);
-- Yellow Gems
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (40123, 40124, 40125, 40126, 40127, 40128);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+28;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40123);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40124);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40125);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40126);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40127);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40128);
-- Purple Gems
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (40129, 40130, 40131, 40132, 40133, 40134, 40135, 40136, 40137, 40138, 40139, 40140, 40141);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+29;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40129);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40130);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40131);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40132);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40133);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40134);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40135);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40136);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40137);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40138);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40139);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40140);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40141);
-- Green Gems
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (40164, 40165, 40166, 40167, 40168, 40169, 40170, 40171, 40172, 40173, 40174, 40175, 40176, 40177, 40178, 40179, 40180, 40181, 40182);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+30;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+30, 40164);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+30, 40165);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+30, 40166);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+30, 40167);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+30, 40168);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+30, 40169);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+30, 40170);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+30, 40171);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+30, 40172);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+30, 40173);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+30, 40174);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+30, 40175);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+30, 40176);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+30, 40177);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+30, 40178);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+30, 40179);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+30, 40180);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+30, 40181);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+30, 40182);
-- Orange Gems
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (40142, 40143, 40144, 40145, 40146, 40147, 40148, 40149, 40150, 40151, 40152, 40153, 40154, 40155, 40156, 40157, 40158, 40159, 40160, 40161, 40162, 40163);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+31;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+31, 40142);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+31, 40143);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+31, 40144);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+31, 40145);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+31, 40146);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+31, 40147);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+31, 40148);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+31, 40149);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+31, 40150);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+31, 40151);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+31, 40152);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+31, 40153);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+31, 40154);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+31, 40155);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+31, 40156);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+31, 40157);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+31, 40158);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+31, 40159);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+31, 40160);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+31, 40161);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+31, 40162);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+31, 40163);



-- Glyphs
-- Priest
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+32;
-- Major
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42404, 42414, 42396, 42403, 45753, 45755, 45756, 45757, 45758, 45760, 42405, 42409, 42417, 42399, 42400, 42401, 42407, 42412, 42397, 42415, 42410, 42402, 42406, 42398, 42411, 42408, 42416);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+32, 42404);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+32, 42414);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+32, 42396);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+32, 42403);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+32, 45753);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+32, 45755);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+32, 45756);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+32, 45757);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+32, 45758);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+32, 45760);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+32, 42405);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+32, 42409);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+32, 42417);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+32, 42399);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+32, 42400);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+32, 42401);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+32, 42407);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+32, 42412);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+32, 42397);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+32, 42415);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+32, 42410);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+32, 42402);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+32, 42406);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+32, 42398);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+32, 42411);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+32, 42408);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+32, 42416);
-- Minor
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43374, 43370, 43372, 43373, 43342, 43371);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+32, 43374);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+32, 43370);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+32, 43372);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+32, 43373);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+32, 43342);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+32, 43371);
-- Paladin
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+33;
-- Major
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (41107, 41101, 43867, 43868, 43869, 41097, 45741, 45742, 45743, 45744, 45745, 45746, 45747, 41109, 41104, 41110, 41102, 41094, 41098, 41099, 41103, 41105, 41100, 41096, 41108, 41095, 41092, 41106);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+33, 41107);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+33, 41101);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+33, 43867);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+33, 43868);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+33, 43869);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+33, 41097);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+33, 45741);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+33, 45742);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+33, 45743);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+33, 45744);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+33, 45745);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+33, 45746);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+33, 45747);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+33, 41109);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+33, 41104);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+33, 41110);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+33, 41102);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+33, 41094);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+33, 41098);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+33, 41099);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+33, 41103);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+33, 41105);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+33, 41100);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+33, 41096);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+33, 41108);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+33, 41095);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+33, 41092);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+33, 41106);
-- Minor
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43369, 43365, 43368, 43366, 43367, 43340);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+33, 43369);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+33, 43365);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+33, 43368);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+33, 43366);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+33, 43367);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+33, 43340);
-- Warrior
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+34;
-- Major
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43419, 43415, 45790, 45792, 45793, 45794, 45795, 45797, 43412, 43421, 43425, 43432, 43428, 43416, 43414, 43426, 43420, 43431, 43424, 43422, 43427, 43429, 43417, 43430, 43413, 43423, 43418);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+34, 43419);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+34, 43415);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+34, 45790);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+34, 45792);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+34, 45793);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+34, 45794);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+34, 45795);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+34, 45797);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+34, 43412);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+34, 43421);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+34, 43425);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+34, 43432);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+34, 43428);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+34, 43416);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+34, 43414);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+34, 43426);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+34, 43420);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+34, 43431);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+34, 43424);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+34, 43422);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+34, 43427);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+34, 43429);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+34, 43417);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+34, 43430);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+34, 43413);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+34, 43423);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+34, 43418);
-- Minor
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (49084, 43400, 43398, 43396, 43399, 43397, 43395);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+34, 49084);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+34, 43400);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+34, 43398);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+34, 43396);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+34, 43399);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+34, 43397);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+34, 43395);
-- Mage
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+35;
-- Major
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (44684, 42748, 42745, 42751, 44955, 42754, 50045, 42736, 45736, 45737, 45738, 45739, 45740, 42749, 42744, 42750, 42737, 42738, 42746, 42747, 42753, 42734, 42741, 42743, 42735, 42752, 42740, 42742, 42739);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+35, 44684);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+35, 42748);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+35, 42745);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+35, 42751);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+35, 44955);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+35, 42754);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+35, 50045);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+35, 42736);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+35, 45736);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+35, 45737);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+35, 45738);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+35, 45739);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+35, 45740);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+35, 42749);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+35, 42744);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+35, 42750);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+35, 42737);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+35, 42738);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+35, 42746);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+35, 42747);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+35, 42753);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+35, 42734);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+35, 42741);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+35, 42743);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+35, 42735);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+35, 42752);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+35, 42740);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+35, 42742);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+35, 42739);
-- Minor
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (44920, 43360, 43357, 43364, 43361, 43362, 43339, 43359);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+35, 44920);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+35, 43360);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+35, 43357);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+35, 43364);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+35, 43361);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+35, 43362);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+35, 43339);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+35, 43359);
-- Warlock
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+36;
-- Major
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42459, 42472, 42457, 42454, 42463, 45779, 45780, 45781, 45782, 45783, 45785, 45789, 42460, 42469, 42453, 42471, 42468, 42466, 42470, 42461, 42455, 42462, 42473, 50077, 42456, 42458, 42465, 42464, 42467);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+36, 42459);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+36, 42472);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+36, 42457);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+36, 42454);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+36, 42463);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+36, 45779);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+36, 45780);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+36, 45781);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+36, 45782);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+36, 45783);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+36, 45785);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+36, 45789);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+36, 42460);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+36, 42469);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+36, 42453);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+36, 42471);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+36, 42468);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+36, 42466);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+36, 42470);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+36, 42461);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+36, 42455);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+36, 42462);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+36, 42473);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+36, 50077);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+36, 42456);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+36, 42458);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+36, 42465);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+36, 42464);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+36, 42467);
-- Minor
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43392, 43394, 43393, 43391, 43390, 43389);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+36, 43392);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+36, 43394);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+36, 43393);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+36, 43391);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+36, 43390);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+36, 43389);
-- Shaman
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+37;
-- Major
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (41529, 41524, 41552, 41517, 41538, 41539, 45770, 45771, 45772, 45775, 45776, 45777, 45778, 41518, 41527, 41542, 41533, 41535, 41541, 41547, 41530, 41531, 41532, 41540, 41537, 41526, 41534, 41536);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+37, 41529);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+37, 41524);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+37, 41552);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+37, 41517);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+37, 41538);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+37, 41539);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+37, 45770);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+37, 45771);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+37, 45772);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+37, 45775);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+37, 45776);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+37, 45777);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+37, 45778);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+37, 41518);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+37, 41527);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+37, 41542);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+37, 41533);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+37, 41535);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+37, 41541);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+37, 41547);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+37, 41530);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+37, 41531);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+37, 41532);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+37, 41540);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+37, 41537);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+37, 41526);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+37, 41534);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+37, 41536);
-- Minor
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (44923, 43381, 43385, 43388, 43344, 43386, 43725);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+37, 44923);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+37, 43381);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+37, 43385);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+37, 43388);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+37, 43344);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+37, 43386);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+37, 43725);
-- Druid
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+38;
-- Major
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (40915, 44928, 40921, 40900, 40906, 40908, 40920, 45601, 45602, 45603, 45604, 45622, 45623, 40896, 40903, 40901, 40902, 40909, 40916, 40919, 46372, 48720, 40912, 40899, 40923, 40897, 40914, 40924, 40913, 50125, 40922);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 40915);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 44928);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 40921);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 40900);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 40906);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 40908);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 40920);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 45601);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 45602);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 45603);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 45604);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 45622);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 45623);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 40896);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 40903);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 40901);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 40902);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 40909);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 40916);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 40919);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 46372);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 48720);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 40912);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 40899);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 40923);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 40897);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 40914);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 40924);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 40913);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 50125);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 40922);
-- Minor
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (44922, 43334, 43331, 43316, 43674, 43332, 43335);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 44922);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 43334);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 43331);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 43316);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 43674);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 43332);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+38, 43335);
-- Hunter
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+39;
-- Major
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42913, 42914, 42902, 42915, 42916, 42917, 45625, 45731, 45732, 45733, 45734, 45735, 42899, 42906, 42911, 42897, 42903, 42904, 42905, 42910, 42908, 42901, 42909, 42898, 42907, 42900, 42912);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+39, 42913);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+39, 42914);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+39, 42902);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+39, 42915);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+39, 42916);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+39, 42917);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+39, 45625);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+39, 45731);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+39, 45732);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+39, 45733);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+39, 45734);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+39, 45735);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+39, 42899);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+39, 42906);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+39, 42911);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+39, 42897);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+39, 42903);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+39, 42904);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+39, 42905);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+39, 42910);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+39, 42908);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+39, 42901);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+39, 42909);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+39, 42898);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+39, 42907);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+39, 42900);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+39, 42912);
-- Minor
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43355, 43351, 43338, 43354, 43356, 43350);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+39, 43355);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+39, 43351);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+39, 43338);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+39, 43354);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+39, 43356);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+39, 43350);
-- Rogue
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+40;
-- Major
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42971, 42959, 42954, 45761, 45762, 45764, 45766, 45767, 45768, 45769, 45908, 42957, 42967, 42968, 42958, 42965, 42969, 42955, 42963, 42962, 42964, 42970, 42973, 42974, 42960, 42966, 42956, 42961, 42972);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+40, 42971);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+40, 42959);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+40, 42954);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+40, 45761);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+40, 45762);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+40, 45764);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+40, 45766);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+40, 45767);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+40, 45768);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+40, 45769);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+40, 45908);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+40, 42957);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+40, 42967);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+40, 42968);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+40, 42958);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+40, 42965);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+40, 42969);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+40, 42955);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+40, 42963);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+40, 42962);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+40, 42964);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+40, 42970);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+40, 42973);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+40, 42974);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+40, 42960);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+40, 42966);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+40, 42956);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+40, 42961);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+40, 42972);
-- Minor
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43378, 43376, 43380, 43377, 43379, 43343);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+40, 43378);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+40, 43376);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+40, 43380);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+40, 43377);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+40, 43379);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+40, 43343);
-- Death Knight
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+41;
-- Major
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43533, 43534, 43536, 43537, 43538, 43541, 43542, 43543, 43545, 43546, 43547, 43548, 43549, 43550, 43551, 43552, 43553, 43554, 43825, 43826, 43827, 45799, 45800, 45803, 45804, 45805, 45806);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+41, 43533);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+41, 43534);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+41, 43536);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+41, 43537);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+41, 43538);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+41, 43541);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+41, 43542);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+41, 43543);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+41, 43545);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+41, 43546);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+41, 43547);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+41, 43548);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+41, 43549);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+41, 43550);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+41, 43551);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+41, 43552);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+41, 43553);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+41, 43554);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+41, 43825);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+41, 43826);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+41, 43827);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+41, 45799);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+41, 45800);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+41, 45803);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+41, 45804);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+41, 45805);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+41, 45806);
-- Minor
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43535, 43539, 43544, 43671, 43672, 43673);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+41, 43535);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+41, 43539);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+41, 43544);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+41, 43671);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+41, 43672);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+41, 43673);
