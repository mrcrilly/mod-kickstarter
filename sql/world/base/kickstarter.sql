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
INSERT INTO `npc_text` (`ID`, `text0_0`) VALUES (@Entry, 'What do you need?');
DELETE FROM `npc_text` WHERE `ID`=@Entry+1;
INSERT INTO `npc_text` (`ID`, `text0_0`) VALUES (@Entry+1, 'Which specialization?');
DELETE FROM `npc_text` WHERE `ID`=@Entry+2;
INSERT INTO `npc_text` (`ID`, `text0_0`) VALUES (@Entry+2, 'Which color do you need?');
DELETE FROM `npc_text` WHERE `ID`=@Entry+3;
INSERT INTO `npc_text` (`ID`, `text0_0`) VALUES (@Entry+3, 'Major or minor?');
DELETE FROM `npc_text` WHERE `ID`=@Entry+4;
INSERT INTO `npc_text` (`ID`, `text0_0`) VALUES (@Entry+4, 'You need to remove all of your equipment before I help you with this.');
DELETE FROM `npc_text` WHERE `ID`=@Entry+5;
INSERT INTO `npc_text` (`ID`, `text0_0`) VALUES (@Entry+5, 'I\'m afraid this service is only available to those at the maximum level...');

/*-- Gems
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
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+41, 43673);*/
