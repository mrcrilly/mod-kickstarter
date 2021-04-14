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
@NPCFlag  := 1,
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
INSERT INTO `npc_text` (`ID`, `text0_0`) VALUES (@Entry, 'What do you need?');
DELETE FROM `npc_text` WHERE `ID`=@Entry+1;
INSERT INTO `npc_text` (`ID`, `text0_0`) VALUES (@Entry+1, 'Which specialization?');
DELETE FROM `npc_text` WHERE `ID`=@Entry+2;
INSERT INTO `npc_text` (`ID`, `text0_0`) VALUES (@Entry+2, 'What type do you want?');
DELETE FROM `npc_text` WHERE `ID`=@Entry+3;
INSERT INTO `npc_text` (`ID`, `text0_0`) VALUES (@Entry+3, 'You need to remove all of your equipment before I can help you with this.');
DELETE FROM `npc_text` WHERE `ID`=@Entry+4;
INSERT INTO `npc_text` (`ID`, `text0_0`) VALUES (@Entry+4, 'I\'m afraid this service is only available to those who have reached level 80.');
