#include "Player.h"
#include "ScriptedGossip.h"
#include "Chat.h"
#include "ScriptMgr.h"
#include "Config.h"

#include "Kickstarter.h"

class Kickstarter : public CreatureScript
{
    public:
        Kickstarter() : CreatureScript("Kickstarter") { }

        bool OnGossipHello(Player* player, Creature* creature)
        {
            ClearGossipMenuFor(player);

            if (sConfigMgr->GetBoolDefault("Kickstarter.Equipment", false))
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want some equipment", GOSSIP_SENDER_MAIN, ID_EQUIPMENT);

            if (sConfigMgr->GetBoolDefault("Kickstarter.Gems", false))
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want some gems", GOSSIP_SENDER_MAIN, ID_GEMS);

            if (sConfigMgr->GetBoolDefault("Kickstarter.Glyphs", false))
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want some glyphs", GOSSIP_SENDER_MAIN, ID_GLYPHS);

            if (sConfigMgr->GetBoolDefault("Kickstarter.Spells", false))
                AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "I want spells specific to my class", GOSSIP_SENDER_MAIN, ID_SPELLS);

            if (sConfigMgr->GetBoolDefault("Kickstarter.Proficiency", false))
                AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "I want any weapon skills available to me", GOSSIP_SENDER_MAIN, ID_PROFICIENCY);

            if (sConfigMgr->GetBoolDefault("Kickstarter.Mounts", false))
                AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "I want to be able to ride creatures", GOSSIP_SENDER_MAIN, ID_MOUNTS);

            SendGossipMenuFor(player, TEXT_KICKSTARTER, creature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
        {
            if (sender != GOSSIP_SENDER_MAIN)
            {
                return false;
            }

            // Equipment
            if (action == ID_EQUIPMENT)
            {
                if (player->getLevel() == 80)
                {
                    ClearGossipMenuFor(player);

                    for (int i = EQUIPMENT_SLOT_START; i != EQUIPMENT_SLOT_END; ++i)
                    {
                        if (player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                        {
                            SendGossipMenuFor(player, TEXT_KICKSTARTER+4, creature->GetGUID());
                            return false;
                        }
                    }

                    switch (player->getClass())
                    {
                        case CLASS_PRIEST:
                            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Discipline", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+1);
                            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Holy", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+2);
                            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Shadow", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+3);
                            break;
                        case CLASS_PALADIN:
                            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Holy", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+4);
                            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Protection", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+5);
                            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Retribution", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+6);
                            break;
                        case CLASS_WARRIOR:
                            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Arms", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+7);
                            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Fury", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+8);
                            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Protection", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+9);
                            break;
                        case CLASS_MAGE:
                            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Arcane", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+10);
                            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Fire", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+11);
                            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Frost", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+12);
                            break;
                        case CLASS_WARLOCK:
                            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Affliction", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+13);
                            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Demonology", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+14);
                            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Destruction", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+15);
                            break;
                        case CLASS_SHAMAN:
                            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Elemental", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+16);
                            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Enhancement", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+17);
                            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Restoration", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+18);
                            break;
                        case CLASS_DRUID:
                            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Balance", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+19);
                            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Feral Combat", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+20);
                            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Restoration", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+21);
                            break;
                        case CLASS_HUNTER:
                            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Beast Mastery", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+22);
                            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Marksmanship", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+23);
                            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Survival", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+24);
                            break;
                        case CLASS_ROGUE:
                            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Assassination", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+25);
                            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Combat", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+26);
                            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Subtlety", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+27);
                            break;
                        case CLASS_DEATH_KNIGHT:
                            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Blood", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+28);
                            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Frost", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+29);
                            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Unholy", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+30);
                            break;
                        default:
                            break;
                    }

                    SendGossipMenuFor(player, TEXT_KICKSTARTER+1, creature->GetGUID());
                }
                else
                {
                    ClearGossipMenuFor(player);
                    SendGossipMenuFor(player, TEXT_KICKSTARTER+5, creature->GetGUID());
                }
            }

            // Priest: Discipline
            if (action == ID_EQUIPMENT+1)
            {
                if (!player->HasSpell(DAGGERS))
                    player->learnSpell(DAGGERS);

                player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 38737, true);
                player->EquipNewItem(EQUIPMENT_SLOT_NECK, 42793, true);
                player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 42842, true);
                player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 42792, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 42788, true);
                player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 42795, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FEET, 42789, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 43855, true);
                player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 38741, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 42791, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 43903, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 38763, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 38764, true);
                player->EquipNewItem(EQUIPMENT_SLOT_BACK, 43925, true);
                player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 42811, true);
                player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 42796, true);
                player->EquipNewItem(EQUIPMENT_SLOT_RANGED, 43828, true);
                player->CLOSE_GOSSIP_MENU();
            }

            // Priest: Holy
            if (action == ID_EQUIPMENT+2)
            {
                if (!player->HasSpell(DAGGERS))
                    player->learnSpell(DAGGERS);

                player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 38737, true);
                player->EquipNewItem(EQUIPMENT_SLOT_NECK, 42793, true);
                player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 42842, true);
                player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 42792, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 42788, true);
                player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 42795, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FEET, 42789, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 43855, true);
                player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 38741, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 42791, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 43903, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 38763, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 38764, true);
                player->EquipNewItem(EQUIPMENT_SLOT_BACK, 43925, true);
                player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 42811, true);
                player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 42796, true);
                player->EquipNewItem(EQUIPMENT_SLOT_RANGED, 43828, true);
                player->CLOSE_GOSSIP_MENU();
            }

            // Priest: Shadow
            if (action == ID_EQUIPMENT+3)
            {
                if (!player->HasSpell(DAGGERS))
                    player->learnSpell(DAGGERS);

                player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 42843, true);
                player->EquipNewItem(EQUIPMENT_SLOT_NECK, 43884, true);
                player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 43862, true);
                player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 42792, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 43866, true);
                player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 42841, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FEET, 43839, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 38739, true);
                player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 43856, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 42845, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 42791, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 38765, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 38764, true);
                player->EquipNewItem(EQUIPMENT_SLOT_BACK, 43925, true);
                player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 42811, true);
                player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 42796, true);
                player->EquipNewItem(EQUIPMENT_SLOT_RANGED, 43828, true);
                player->CLOSE_GOSSIP_MENU();
            }

            // Paladin: Holy
            if (action == ID_EQUIPMENT+4)
            {
                if (!player->HasSpell(MAIL))
                    player->learnSpell(MAIL);
                if (!player->HasSpell(PLATE_MAIL))
                    player->learnSpell(PLATE_MAIL);
                if (!player->HasSpell(ONE_HANDED_MACES))
                    player->learnSpell(ONE_HANDED_MACES);
                if (!player->HasSpell(SHIELD))
                    player->learnSpell(SHIELD);

                player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 42829, true);
                player->EquipNewItem(EQUIPMENT_SLOT_NECK, 42793, true);
                player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 42876, true);
                player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 42877, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 43831, true);
                player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 42881, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FEET, 42883, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 42830, true);
                player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 43943, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 42791, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 43874, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 38763, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 38764, true);
                player->EquipNewItem(EQUIPMENT_SLOT_BACK, 43925, true);
                player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 39143, true);
                player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 42860, true);
                player->CLOSE_GOSSIP_MENU();
            }

            // Paladin: Protection
            if (action == ID_EQUIPMENT+5)
            {
                if (!player->HasSpell(MAIL))
                    player->learnSpell(MAIL);
                if (!player->HasSpell(PLATE_MAIL))
                    player->learnSpell(PLATE_MAIL);
                if (!player->HasSpell(ONE_HANDED_SWORDS))
                    player->learnSpell(ONE_HANDED_SWORDS);
                if (!player->HasSpell(SHIELD))
                    player->learnSpell(SHIELD);

                player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 42879, true);
                player->EquipNewItem(EQUIPMENT_SLOT_NECK, 43849, true);
                player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 43844, true);
                player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 42827, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 39471, true);
                player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 43845, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FEET, 42884, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 42825, true);
                player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 43842, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 39482, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 39481, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 43838, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 43829, true);
                player->EquipNewItem(EQUIPMENT_SLOT_BACK, 43924, true);
                player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 43923, true);
                player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 43843, true);
                player->CLOSE_GOSSIP_MENU();
            }

            // Paladin: Retribution
            if (action == ID_EQUIPMENT+6)
            {
                if (!player->HasSpell(MAIL))
                    player->learnSpell(MAIL);
                if (!player->HasSpell(PLATE_MAIL))
                    player->learnSpell(PLATE_MAIL);
                if (!player->HasSpell(TWO_HANDED_SWORDS))
                    player->learnSpell(TWO_HANDED_SWORDS);

                player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 42878, true);
                player->EquipNewItem(EQUIPMENT_SLOT_NECK, 42808, true);
                player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 42834, true);
                player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 43945, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 42882, true);
                player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 42832, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FEET, 42833, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 39100, true);
                player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 42835, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 42864, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 39481, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 43838, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 43829, true);
                player->EquipNewItem(EQUIPMENT_SLOT_BACK, 43924, true);
                player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 43832, true);
                player->CLOSE_GOSSIP_MENU();
            }

            // Warrior: Arms
            if (action == ID_EQUIPMENT+7)
            {
                if (!player->HasSpell(MAIL))
                    player->learnSpell(MAIL);
                if (!player->HasSpell(PLATE_MAIL))
                    player->learnSpell(PLATE_MAIL);
                if (!player->HasSpell(ONE_HANDED_SWORDS))
                    player->learnSpell(ONE_HANDED_SWORDS);
                if (!player->HasSpell(BOWS))
                    player->learnSpell(BOWS);

                player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 42878, true);
                player->EquipNewItem(EQUIPMENT_SLOT_NECK, 42808, true);
                player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 42834, true);
                player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 43945, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 42882, true);
                player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 42832, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FEET, 42833, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 39100, true);
                player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 42835, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 42864, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 39481, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 43838, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 43829, true);
                player->EquipNewItem(EQUIPMENT_SLOT_BACK, 43924, true);
                player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 43923, true);
                player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 42786, true);
                player->EquipNewItem(EQUIPMENT_SLOT_RANGED, 39134, true);
                player->CLOSE_GOSSIP_MENU();
            }

            // Warrior: Fury
            if (action == ID_EQUIPMENT+8)
            {
                if (!player->HasSpell(MAIL))
                    player->learnSpell(MAIL);
                if (!player->HasSpell(PLATE_MAIL))
                    player->learnSpell(PLATE_MAIL);
                if (!player->HasSpell(ONE_HANDED_SWORDS))
                    player->learnSpell(ONE_HANDED_SWORDS);
                if (!player->HasSpell(BOWS))
                    player->learnSpell(BOWS);

                player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 42878, true);
                player->EquipNewItem(EQUIPMENT_SLOT_NECK, 42808, true);
                player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 42834, true);
                player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 43945, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 42882, true);
                player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 42832, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FEET, 42833, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 39100, true);
                player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 42835, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 42864, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 39481, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 43838, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 43829, true);
                player->EquipNewItem(EQUIPMENT_SLOT_BACK, 43924, true);
                player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 43923, true);
                player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 42786, true);
                player->EquipNewItem(EQUIPMENT_SLOT_RANGED, 39134, true);
                player->CLOSE_GOSSIP_MENU();
            }

            // Warrior: Protection
            if (action == ID_EQUIPMENT+9)
            {
                if (!player->HasSpell(MAIL))
                    player->learnSpell(MAIL);
                if (!player->HasSpell(PLATE_MAIL))
                    player->learnSpell(PLATE_MAIL);
                if (!player->HasSpell(ONE_HANDED_SWORDS))
                    player->learnSpell(ONE_HANDED_SWORDS);
                if (!player->HasSpell(BOWS))
                    player->learnSpell(BOWS);
                if (!player->HasSpell(SHIELD))
                    player->learnSpell(SHIELD);

                player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 42879, true);
                player->EquipNewItem(EQUIPMENT_SLOT_NECK, 43849, true);
                player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 43844, true);
                player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 42827, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 39471, true);
                player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 43845, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FEET, 42884, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 42825, true);
                player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 43842, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 39482, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 39481, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 43838, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 43829, true);
                player->EquipNewItem(EQUIPMENT_SLOT_BACK, 43924, true);
                player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 43923, true);
                player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 43843, true);
                player->EquipNewItem(EQUIPMENT_SLOT_RANGED, 39134, true);
                player->CLOSE_GOSSIP_MENU();
            }

            // Mage: Arcane
            if (action == ID_EQUIPMENT+10)
            {
                if (!player->HasSpell(DAGGERS))
                    player->learnSpell(DAGGERS);

                player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 42843, true);
                player->EquipNewItem(EQUIPMENT_SLOT_NECK, 43884, true);
                player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 43862, true);
                player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 42792, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 43866, true);
                player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 42841, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FEET, 43839, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 38739, true);
                player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 43856, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 42845, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 42791, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 38765, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 38764, true);
                player->EquipNewItem(EQUIPMENT_SLOT_BACK, 43925, true);
                player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 42811, true);
                player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 42796, true);
                player->EquipNewItem(EQUIPMENT_SLOT_RANGED, 43828, true);
                player->CLOSE_GOSSIP_MENU();
            }

            // Mage: Fire
            if (action == ID_EQUIPMENT+11)
            {
                if (!player->HasSpell(DAGGERS))
                    player->learnSpell(DAGGERS);

                player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 42843, true);
                player->EquipNewItem(EQUIPMENT_SLOT_NECK, 43884, true);
                player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 43862, true);
                player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 42792, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 43866, true);
                player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 42841, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FEET, 43839, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 38739, true);
                player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 43856, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 42845, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 42791, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 38765, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 38764, true);
                player->EquipNewItem(EQUIPMENT_SLOT_BACK, 43925, true);
                player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 42811, true);
                player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 42796, true);
                player->EquipNewItem(EQUIPMENT_SLOT_RANGED, 43828, true);
                player->CLOSE_GOSSIP_MENU();
            }

            // Mage: Frost
            if (action == ID_EQUIPMENT+12)
            {
                if (!player->HasSpell(DAGGERS))
                    player->learnSpell(DAGGERS);

                player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 42843, true);
                player->EquipNewItem(EQUIPMENT_SLOT_NECK, 43884, true);
                player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 43862, true);
                player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 42792, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 43866, true);
                player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 42841, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FEET, 43839, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 38739, true);
                player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 43856, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 42845, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 42791, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 38765, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 38764, true);
                player->EquipNewItem(EQUIPMENT_SLOT_BACK, 43925, true);
                player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 42811, true);
                player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 42796, true);
                player->EquipNewItem(EQUIPMENT_SLOT_RANGED, 43828, true);
                player->CLOSE_GOSSIP_MENU();
            }

            // Warlock: Affliction
            if (action == ID_EQUIPMENT+13)
            {
                if (!player->HasSpell(DAGGERS))
                    player->learnSpell(DAGGERS);

                player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 42843, true);
                player->EquipNewItem(EQUIPMENT_SLOT_NECK, 43884, true);
                player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 43862, true);
                player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 42792, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 43866, true);
                player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 42841, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FEET, 43839, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 38739, true);
                player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 43856, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 42845, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 42791, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 38765, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 38764, true);
                player->EquipNewItem(EQUIPMENT_SLOT_BACK, 43925, true);
                player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 42811, true);
                player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 42796, true);
                player->EquipNewItem(EQUIPMENT_SLOT_RANGED, 43828, true);
                player->CLOSE_GOSSIP_MENU();
            }

            // Warlock: Demonology
            if (action == ID_EQUIPMENT+14)
            {
                if (!player->HasSpell(DAGGERS))
                    player->learnSpell(DAGGERS);

                player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 42843, true);
                player->EquipNewItem(EQUIPMENT_SLOT_NECK, 43884, true);
                player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 43862, true);
                player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 42792, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 43866, true);
                player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 42841, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FEET, 43839, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 38739, true);
                player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 43856, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 42845, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 42791, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 38765, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 38764, true);
                player->EquipNewItem(EQUIPMENT_SLOT_BACK, 43925, true);
                player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 42811, true);
                player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 42796, true);
                player->EquipNewItem(EQUIPMENT_SLOT_RANGED, 43828, true);
                player->CLOSE_GOSSIP_MENU();
            }

            // Warlock: Destruction
            if (action == ID_EQUIPMENT+15)
            {
                if (!player->HasSpell(DAGGERS))
                    player->learnSpell(DAGGERS);

                player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 42843, true);
                player->EquipNewItem(EQUIPMENT_SLOT_NECK, 43884, true);
                player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 43862, true);
                player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 42792, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 43866, true);
                player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 42841, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FEET, 43839, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 38739, true);
                player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 43856, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 42845, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 42791, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 38765, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 38764, true);
                player->EquipNewItem(EQUIPMENT_SLOT_BACK, 43925, true);
                player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 42811, true);
                player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 42796, true);
                player->EquipNewItem(EQUIPMENT_SLOT_RANGED, 43828, true);
                player->CLOSE_GOSSIP_MENU();
            }

            // Shaman: Elemental
            if (action == ID_EQUIPMENT+16)
            {
                if (!player->HasSpell(MAIL))
                    player->learnSpell(MAIL);
                if (!player->HasSpell(ONE_HANDED_MACES))
                    player->learnSpell(ONE_HANDED_MACES);
                if (!player->HasSpell(SHIELD))
                    player->learnSpell(SHIELD);

                player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 42810, true);
                player->EquipNewItem(EQUIPMENT_SLOT_NECK, 43884, true);
                player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 43830, true);
                player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 43935, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 42814, true);
                player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 42890, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FEET, 42815, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 42888, true);
                player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 43976, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 42791, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 42845, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 38765, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 38764, true);
                player->EquipNewItem(EQUIPMENT_SLOT_BACK, 43925, true);
                player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 39143, true);
                player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 42860, true);
                player->CLOSE_GOSSIP_MENU();
            }

            // Shaman: Enhancement
            if (action == ID_EQUIPMENT+17)
            {
                if (!player->HasSpell(MAIL))
                    player->learnSpell(MAIL);
                if (!player->HasSpell(ONE_HANDED_MACES))
                    player->learnSpell(ONE_HANDED_MACES);

                player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 42895, true);
                player->EquipNewItem(EQUIPMENT_SLOT_NECK, 42808, true);
                player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 42887, true);
                player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 42813, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 39065, true);
                player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 42817, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FEET, 42891, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 42816, true);
                player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 39070, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 39480, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 43926, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 43838, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 43829, true);
                player->EquipNewItem(EQUIPMENT_SLOT_BACK, 43889, true);
                player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 43888, true);
                player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 39144, true);
                player->CLOSE_GOSSIP_MENU();
            }

            // Shaman: Restoration
            if (action == ID_EQUIPMENT+18)
            {
                if (!player->HasSpell(MAIL))
                    player->learnSpell(MAIL);
                if (!player->HasSpell(ONE_HANDED_MACES))
                    player->learnSpell(ONE_HANDED_MACES);
                if (!player->HasSpell(SHIELD))
                    player->learnSpell(SHIELD);

                player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 42810, true);
                player->EquipNewItem(EQUIPMENT_SLOT_NECK, 42793, true);
                player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 43830, true);
                player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 43935, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 42814, true);
                player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 42890, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FEET, 42815, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 42888, true);
                player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 43976, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 42791, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 43874, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 38763, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 38764, true);
                player->EquipNewItem(EQUIPMENT_SLOT_BACK, 43925, true);
                player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 39143, true);
                player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 42860, true);
                player->CLOSE_GOSSIP_MENU();
            }

            // Druid: Balance
            if (action == ID_EQUIPMENT+19)
            {
                if (!player->HasSpell(STAVES))
                    player->learnSpell(STAVES);

                player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 43905, true);
                player->EquipNewItem(EQUIPMENT_SLOT_NECK, 43884, true);
                player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 42800, true);
                player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 42803, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 43914, true);
                player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 39413, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FEET, 43908, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 42865, true);
                player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 43910, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 42791, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 42845, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 38764, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 38765, true);
                player->EquipNewItem(EQUIPMENT_SLOT_BACK, 43925, true);
                player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 39121, true);
                player->CLOSE_GOSSIP_MENU();
            }

            // Druid: Feral Combat
            if (action == ID_EQUIPMENT+20)
            {
                if (!player->HasSpell(STAVES))
                    player->learnSpell(STAVES);

                player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 42872, true);
                player->EquipNewItem(EQUIPMENT_SLOT_NECK, 42808, true);
                player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 42869, true);
                player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 39036, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 43892, true);
                player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 43896, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FEET, 42804, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 42871, true);
                player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 43904, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 42812, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 39480, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 43838, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 43829, true);
                player->EquipNewItem(EQUIPMENT_SLOT_BACK, 43889, true);
                player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 43920, true);
                player->CLOSE_GOSSIP_MENU();
            }

            // Druid: Restoration
            if (action == ID_EQUIPMENT+21)
            {
                if (!player->HasSpell(STAVES))
                    player->learnSpell(STAVES);

                player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 43905, true);
                player->EquipNewItem(EQUIPMENT_SLOT_NECK, 42793, true);
                player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 42800, true);
                player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 42803, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 43914, true);
                player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 39413, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FEET, 43908, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 42865, true);
                player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 43910, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 42791, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 43874, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 38764, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 38763, true);
                player->EquipNewItem(EQUIPMENT_SLOT_BACK, 43925, true);
                player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 39121, true);
                player->CLOSE_GOSSIP_MENU();
            }

            // Hunter: Beast Mastery
            if (action == ID_EQUIPMENT+22)
            {
                if (!player->HasSpell(MAIL))
                    player->learnSpell(MAIL);
                if (!player->HasSpell(DAGGERS))
                    player->learnSpell(DAGGERS);
                if (!player->HasSpell(BOWS))
                    player->learnSpell(BOWS);

                player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 42895, true);
                player->EquipNewItem(EQUIPMENT_SLOT_NECK, 42808, true);
                player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 42887, true);
                player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 42813, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 39065, true);
                player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 42817, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FEET, 42891, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 42816, true);
                player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 39070, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 39480, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 43926, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 43838, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 43829, true);
                player->EquipNewItem(EQUIPMENT_SLOT_BACK, 43889, true);
                player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 39130, true);
                player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 43915, true);
                player->EquipNewItem(EQUIPMENT_SLOT_RANGED, 43928, true);
                player->CLOSE_GOSSIP_MENU();
            }

            // Hunter: Marksmanship
            if (action == ID_EQUIPMENT+23)
            {
                if (!player->HasSpell(MAIL))
                    player->learnSpell(MAIL);
                if (!player->HasSpell(DAGGERS))
                    player->learnSpell(DAGGERS);
                if (!player->HasSpell(BOWS))
                    player->learnSpell(BOWS);

                player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 42895, true);
                player->EquipNewItem(EQUIPMENT_SLOT_NECK, 42808, true);
                player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 42887, true);
                player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 42813, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 39065, true);
                player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 42817, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FEET, 42891, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 42816, true);
                player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 39070, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 39480, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 43926, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 43838, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 43829, true);
                player->EquipNewItem(EQUIPMENT_SLOT_BACK, 43889, true);
                player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 39130, true);
                player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 43915, true);
                player->EquipNewItem(EQUIPMENT_SLOT_RANGED, 43928, true);
                player->CLOSE_GOSSIP_MENU();
            }

            // Hunter: Survival
            if (action == ID_EQUIPMENT+24)
            {
                if (!player->HasSpell(MAIL))
                    player->learnSpell(MAIL);
                if (!player->HasSpell(DAGGERS))
                    player->learnSpell(DAGGERS);
                if (!player->HasSpell(BOWS))
                    player->learnSpell(BOWS);

                player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 42895, true);
                player->EquipNewItem(EQUIPMENT_SLOT_NECK, 42808, true);
                player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 42887, true);
                player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 42813, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 39065, true);
                player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 42817, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FEET, 42891, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 42816, true);
                player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 39070, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 39480, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 43926, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 43838, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 43829, true);
                player->EquipNewItem(EQUIPMENT_SLOT_BACK, 43889, true);
                player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 39130, true);
                player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 43915, true);
                player->EquipNewItem(EQUIPMENT_SLOT_RANGED, 43928, true);
                player->CLOSE_GOSSIP_MENU();
            }

            // Rogue: Assassination
            if (action == ID_EQUIPMENT+25)
            {
                if (!player->HasSpell(DAGGERS))
                    player->learnSpell(DAGGERS);

                player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 42872, true);
                player->EquipNewItem(EQUIPMENT_SLOT_NECK, 42808, true);
                player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 42869, true);
                player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 39036, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 43892, true);
                player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 43896, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FEET, 42804, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 42871, true);
                player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 43904, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 42812, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 39480, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 43838, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 43829, true);
                player->EquipNewItem(EQUIPMENT_SLOT_BACK, 43889, true);
                player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 39130, true);
                player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 43915, true);
                player->EquipNewItem(EQUIPMENT_SLOT_RANGED, 43900, true);
                player->CLOSE_GOSSIP_MENU();
            }

            // Rogue: Combat
            if (action == ID_EQUIPMENT+26)
            {
                if (!player->HasSpell(DAGGERS))
                    player->learnSpell(DAGGERS);

                player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 42872, true);
                player->EquipNewItem(EQUIPMENT_SLOT_NECK, 42808, true);
                player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 42869, true);
                player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 39036, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 43892, true);
                player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 43896, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FEET, 42804, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 42871, true);
                player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 43904, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 42812, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 39480, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 43838, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 43829, true);
                player->EquipNewItem(EQUIPMENT_SLOT_BACK, 43889, true);
                player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 39130, true);
                player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 43915, true);
                player->EquipNewItem(EQUIPMENT_SLOT_RANGED, 43900, true);
                player->CLOSE_GOSSIP_MENU();
            }

            // Rogue: Subtlety
            if (action == ID_EQUIPMENT+27)
            {
                if (!player->HasSpell(DAGGERS))
                    player->learnSpell(DAGGERS);

                player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 42872, true);
                player->EquipNewItem(EQUIPMENT_SLOT_NECK, 42808, true);
                player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 42869, true);
                player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 39036, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 43892, true);
                player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 43896, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FEET, 42804, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 42871, true);
                player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 43904, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 42812, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 39480, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 43838, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 43829, true);
                player->EquipNewItem(EQUIPMENT_SLOT_BACK, 43889, true);
                player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 39130, true);
                player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 43915, true);
                player->EquipNewItem(EQUIPMENT_SLOT_RANGED, 43900, true);
                player->CLOSE_GOSSIP_MENU();
            }

            // Death Knight: Blood
            if (action == ID_EQUIPMENT+28)
            {
                if (!player->HasSpell(MAIL))
                    player->learnSpell(MAIL);
                if (!player->HasSpell(PLATE_MAIL))
                    player->learnSpell(PLATE_MAIL);
                if (!player->HasSpell(TWO_HANDED_SWORDS))
                    player->learnSpell(TWO_HANDED_SWORDS);

                player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 42879, true);
                player->EquipNewItem(EQUIPMENT_SLOT_NECK, 43849, true);
                player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 43844, true);
                player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 42827, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 39471, true);
                player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 43845, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FEET, 42884, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 42825, true);
                player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 43842, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 39482, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 39481, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 43838, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 43829, true);
                player->EquipNewItem(EQUIPMENT_SLOT_BACK, 43924, true);
                player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 43832, true);
                player->CLOSE_GOSSIP_MENU();
            }

            // Death Knight: Frost
            if (action == ID_EQUIPMENT+29)
            {
                if (!player->HasSpell(MAIL))
                    player->learnSpell(MAIL);
                if (!player->HasSpell(PLATE_MAIL))
                    player->learnSpell(PLATE_MAIL);
                if (!player->HasSpell(ONE_HANDED_SWORDS))
                    player->learnSpell(ONE_HANDED_SWORDS);

                player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 42878, true);
                player->EquipNewItem(EQUIPMENT_SLOT_NECK, 42808, true);
                player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 42834, true);
                player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 43945, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 42882, true);
                player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 42832, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FEET, 42833, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 39100, true);
                player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 42835, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 42864, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 39481, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 43838, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 43829, true);
                player->EquipNewItem(EQUIPMENT_SLOT_BACK, 43924, true);
                player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 43923, true);
                player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 42786, true);
                player->CLOSE_GOSSIP_MENU();
            }

            // Death Knight: Unholy
            if (action == ID_EQUIPMENT+30)
            {
                if (!player->HasSpell(MAIL))
                    player->learnSpell(MAIL);
                if (!player->HasSpell(PLATE_MAIL))
                    player->learnSpell(PLATE_MAIL);
                if (!player->HasSpell(ONE_HANDED_SWORDS))
                    player->learnSpell(ONE_HANDED_SWORDS);

                player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 42878, true);
                player->EquipNewItem(EQUIPMENT_SLOT_NECK, 42808, true);
                player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 42834, true);
                player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 43945, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 42882, true);
                player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 42832, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FEET, 42833, true);
                player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 39100, true);
                player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 42835, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 42864, true);
                player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 39481, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 43838, true);
                player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 43829, true);
                player->EquipNewItem(EQUIPMENT_SLOT_BACK, 43924, true);
                player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 43923, true);
                player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 42786, true);
                player->CLOSE_GOSSIP_MENU();
            }

            // Gems
            if (action == ID_GEMS)
            {
                ClearGossipMenuFor(player);

                SendGossipMenuFor(player, TEXT_KICKSTARTER+2, creature->GetGUID());
            }

            // Glyphs
            if (action == ID_GLYPHS)
            {
                ClearGossipMenuFor(player);

                SendGossipMenuFor(player, TEXT_KICKSTARTER+3, creature->GetGUID());
            }

            // Class spells
            if (action == ID_SPELLS)
            {
                switch (player->getClass())
                {
                    case CLASS_PRIEST:
                        for (int i = 0; i < 208; i++)
                        {
                            if (player->getLevel() >= spellPriest[i][1])
                                if (!player->HasSpell(spellPriest[i][0]))
                                    player->learnSpell(spellPriest[i][0]);
                        }

                        for (int i = 0; i < 34; i++)
                        {
                            if (player->HasSpell(talentPriest[i][2]))
                                if (player->getLevel() >= talentPriest[i][1])
                                    if (!player->HasSpell(talentPriest[i][0]))
                                        player->learnSpell(talentPriest[i][0]);
                        }
                        break;
                    case CLASS_PALADIN:
                        for (int i = 0; i < 160; i++)
                        {
                            if (player->getLevel() >= spellPaladin[i][1])
                                if (!player->HasSpell(spellPaladin[i][0]))
                                    player->learnSpell(spellPaladin[i][0]);
                        }

                        for (int i = 0; i < 16; i++)
                        {
                            if (player->HasSpell(talentPaladin[i][2]))
                                if (player->getLevel() >= talentPaladin[i][1])
                                    if (!player->HasSpell(talentPaladin[i][0]))
                                        player->learnSpell(talentPaladin[i][0]);
                        }

                        switch (player->GetTeamId())
                        {
                            case TEAM_ALLIANCE:
                                if (player->getLevel() >= 64)
                                    if (!player->HasSpell(31801))
                                        player->learnSpell(31801);
                                break;
                            case TEAM_HORDE:
                                if (player->getLevel() >= 66)
                                    if (!player->HasSpell(53736))
                                        player->learnSpell(53736);
                                break;
                            default:
                                break;
                        }
                        break;
                    case CLASS_WARRIOR:
                        for (int i = 0; i < 125; i++)
                        {
                            if (player->getLevel() >= spellWarrior[i][1])
                                if (!player->HasSpell(spellWarrior[i][0]))
                                    player->learnSpell(spellWarrior[i][0]);
                        }

                        for (int i = 0; i < 11; i++)
                        {
                            if (player->HasSpell(talentWarrior[i][2]))
                                if (player->getLevel() >= talentWarrior[i][1])
                                    if (!player->HasSpell(talentWarrior[i][0]))
                                        player->learnSpell(talentWarrior[i][0]);
                        }
                        break;
                    case CLASS_MAGE:
                        for (int i = 0; i < 223; i++)
                        {
                            if (player->getLevel() >= spellMage[i][1])
                                if (!player->HasSpell(spellMage[i][0]))
                                    player->learnSpell(spellMage[i][0]);
                        }

                        for (int i = 0; i < 35; i++)
                        {
                            if (player->HasSpell(talentMage[i][2]))
                                if (player->getLevel() >= talentMage[i][1])
                                    if (!player->HasSpell(talentMage[i][0]))
                                        player->learnSpell(talentMage[i][0]);
                        }
                        break;
                    case CLASS_WARLOCK:
                        for (int i = 0; i < 211; i++)
                        {
                            if (player->getLevel() >= spellWarlock[i][1])
                                if (!player->HasSpell(spellWarlock[i][0]))
                                    player->learnSpell(spellWarlock[i][0]);
                        }

                        for (int i = 0; i < 27; i++)
                        {
                            if (player->HasSpell(talentWarlock[i][2]))
                                if (player->getLevel() >= talentWarlock[i][1])
                                    if (!player->HasSpell(talentWarlock[i][0]))
                                        player->learnSpell(talentWarlock[i][0]);
                        }
                        break;
                    case CLASS_SHAMAN:
                        for (int i = 0; i < 266; i++)
                        {
                            if (player->getLevel() >= spellShaman[i][1])
                                if (!player->HasSpell(spellShaman[i][0]))
                                    player->learnSpell(spellShaman[i][0]);
                        }

                        for (int i = 0; i < 13; i++)
                        {
                            if (player->HasSpell(talentShaman[i][2]))
                                if (player->getLevel() >= talentShaman[i][1])
                                    if (!player->HasSpell(talentShaman[i][0]))
                                        player->learnSpell(talentShaman[i][0]);
                        }
                        break;
                    case CLASS_DRUID:
                        for (int i = 0; i < 276; i++)
                        {
                            if (player->getLevel() >= spellDruid[i][1])
                                if (!player->HasSpell(spellDruid[i][0]))
                                    player->learnSpell(spellDruid[i][0]);
                        }

                        for (int i = 0; i < 24; i++)
                        {
                            if (player->HasSpell(talentDruid[i][2]))
                                if (player->getLevel() >= talentDruid[i][1])
                                    if (!player->HasSpell(talentDruid[i][0]))
                                        player->learnSpell(talentDruid[i][0]);
                        }
                        break;
                    case CLASS_HUNTER:
                        for (int i = 0; i < 149; i++)
                        {
                            if (player->getLevel() >= spellHunter[i][1])
                                if (!player->HasSpell(spellHunter[i][0]))
                                    player->learnSpell(spellHunter[i][0]);
                        }

                        for (int i = 0; i < 26; i++)
                        {
                            if (player->HasSpell(talentHunter[i][2]))
                                if (player->getLevel() >= talentHunter[i][1])
                                    if (!player->HasSpell(talentHunter[i][0]))
                                        player->learnSpell(talentHunter[i][0]);
                        }
                        break;
                    case CLASS_ROGUE:
                        for (int i = 0; i < 113; i++)
                        {
                            if (player->getLevel() >= spellRogue[i][1])
                                if (!player->HasSpell(spellRogue[i][0]))
                                    player->learnSpell(spellRogue[i][0]);
                        }

                        for (int i = 0; i < 9; i++)
                        {
                            if (player->HasSpell(talentRogue[i][2]))
                                if (player->getLevel() >= talentRogue[i][1])
                                    if (!player->HasSpell(talentRogue[i][0]))
                                        player->learnSpell(talentRogue[i][0]);
                        }
                        break;
                    case CLASS_DEATH_KNIGHT:
                        for (int i = 0; i < 69; i++)
                        {
                            if (player->getLevel() >= spellDeathKnight[i][1])
                                if (!player->HasSpell(spellDeathKnight[i][0]))
                                    player->learnSpell(spellDeathKnight[i][0]);
                        }

                        for (int i = 0; i < 20; i++)
                        {
                            if (player->HasSpell(talentDeathKnight[i][2]))
                                if (player->getLevel() >= talentDeathKnight[i][1])
                                    if (!player->HasSpell(talentDeathKnight[i][0]))
                                        player->learnSpell(talentDeathKnight[i][0]);
                        }
                        break;
                    default:
                        break;
                }

                player->CLOSE_GOSSIP_MENU();
            }

            // Proficiency
            if (action == ID_PROFICIENCY)
            {
                switch (player->getClass())
                {
                    case CLASS_PRIEST:
                        if (!player->HasSpell(ONE_HANDED_MACES))
                            player->learnSpell(ONE_HANDED_MACES);
                        if (!player->HasSpell(DAGGERS))
                            player->learnSpell(DAGGERS);
                        if (!player->HasSpell(STAVES))
                            player->learnSpell(STAVES);
                        if (!player->HasSpell(WANDS))
                            player->learnSpell(WANDS);
                        break;
                    case CLASS_PALADIN:
                        if (!player->HasSpell(MAIL))
                            player->learnSpell(MAIL);
                        if (!player->HasSpell(PLATE_MAIL))
                            player->learnSpell(PLATE_MAIL);
                        if (!player->HasSpell(POLEARMS))
                            player->learnSpell(POLEARMS);
                        if (!player->HasSpell(ONE_HANDED_MACES))
                            player->learnSpell(ONE_HANDED_MACES);
                        if (!player->HasSpell(TWO_HANDED_MACES))
                            player->learnSpell(TWO_HANDED_MACES);
                        if (!player->HasSpell(ONE_HANDED_SWORDS))
                            player->learnSpell(ONE_HANDED_SWORDS);
                        if (!player->HasSpell(ONE_HANDED_AXES))
                            player->learnSpell(ONE_HANDED_AXES);
                        if (!player->HasSpell(TWO_HANDED_AXES))
                            player->learnSpell(TWO_HANDED_AXES);
                        if (!player->HasSpell(TWO_HANDED_SWORDS))
                            player->learnSpell(TWO_HANDED_SWORDS);
                        if (!player->HasSpell(SHIELD))
                            player->learnSpell(SHIELD);
                        if (!player->HasSpell(PARRY))
                            player->learnSpell(PARRY);
                        if (!player->HasSpell(BLOCK))
                            player->learnSpell(BLOCK);
                        break;
                    case CLASS_WARRIOR:
                        if (!player->HasSpell(MAIL))
                            player->learnSpell(MAIL);
                        if (!player->HasSpell(PLATE_MAIL))
                            player->learnSpell(PLATE_MAIL);
                        if (!player->HasSpell(POLEARMS))
                            player->learnSpell(POLEARMS);
                        if (!player->HasSpell(ONE_HANDED_MACES))
                            player->learnSpell(ONE_HANDED_MACES);
                        if (!player->HasSpell(TWO_HANDED_MACES))
                            player->learnSpell(TWO_HANDED_MACES);
                        if (!player->HasSpell(ONE_HANDED_SWORDS))
                            player->learnSpell(ONE_HANDED_SWORDS);
                        if (!player->HasSpell(ONE_HANDED_AXES))
                            player->learnSpell(ONE_HANDED_AXES);
                        if (!player->HasSpell(TWO_HANDED_SWORDS))
                            player->learnSpell(TWO_HANDED_SWORDS);
                        if (!player->HasSpell(DUAL_WIELD))
                            player->learnSpell(DUAL_WIELD);
                        if (!player->HasSpell(DAGGERS))
                            player->learnSpell(DAGGERS);
                        if (!player->HasSpell(STAVES))
                            player->learnSpell(STAVES);
                        if (!player->HasSpell(FIST_WEAPONS))
                            player->learnSpell(FIST_WEAPONS);
                        if (!player->HasSpell(BOWS))
                            player->learnSpell(BOWS);
                        if (!player->HasSpell(CROSSBOWS))
                            player->learnSpell(CROSSBOWS);
                        if (!player->HasSpell(GUNS))
                            player->learnSpell(GUNS);
                        if (!player->HasSpell(SHIELD))
                            player->learnSpell(SHIELD);
                        if (!player->HasSpell(PARRY))
                            player->learnSpell(PARRY);
                        if (!player->HasSpell(BLOCK))
                            player->learnSpell(BLOCK);
                        break;
                    case CLASS_MAGE:
                        if (!player->HasSpell(ONE_HANDED_SWORDS))
                            player->learnSpell(ONE_HANDED_SWORDS);
                        if (!player->HasSpell(DAGGERS))
                            player->learnSpell(DAGGERS);
                        if (!player->HasSpell(STAVES))
                            player->learnSpell(STAVES);
                        if (!player->HasSpell(WANDS))
                            player->learnSpell(WANDS);
                        break;
                    case CLASS_WARLOCK:
                        if (!player->HasSpell(ONE_HANDED_SWORDS))
                            player->learnSpell(ONE_HANDED_SWORDS);
                        if (!player->HasSpell(DAGGERS))
                            player->learnSpell(DAGGERS);
                        if (!player->HasSpell(STAVES))
                            player->learnSpell(STAVES);
                        if (!player->HasSpell(WANDS))
                            player->learnSpell(WANDS);
                        break;
                    case CLASS_SHAMAN:
                        if (!player->HasSpell(MAIL))
                            player->learnSpell(MAIL);
                        if (!player->HasSpell(ONE_HANDED_MACES))
                            player->learnSpell(ONE_HANDED_MACES);
                        if (!player->HasSpell(TWO_HANDED_MACES))
                            player->learnSpell(TWO_HANDED_MACES);
                        if (!player->HasSpell(ONE_HANDED_AXES))
                            player->learnSpell(ONE_HANDED_AXES);
                        if (!player->HasSpell(TWO_HANDED_AXES))
                            player->learnSpell(TWO_HANDED_AXES);
                        if (!player->HasSpell(DAGGERS))
                            player->learnSpell(DAGGERS);
                        if (!player->HasSpell(STAVES))
                            player->learnSpell(STAVES);
                        if (!player->HasSpell(FIST_WEAPONS))
                            player->learnSpell(FIST_WEAPONS);
                        if (!player->HasSpell(SHIELD))
                            player->learnSpell(SHIELD);
                        if (!player->HasSpell(BLOCK))
                            player->learnSpell(BLOCK);
                        break;
                    case CLASS_DRUID:
                        if (!player->HasSpell(POLEARMS))
                            player->learnSpell(POLEARMS);
                        if (!player->HasSpell(ONE_HANDED_MACES))
                            player->learnSpell(ONE_HANDED_MACES);
                        if (!player->HasSpell(TWO_HANDED_MACES))
                            player->learnSpell(TWO_HANDED_MACES);
                        if (!player->HasSpell(DAGGERS))
                            player->learnSpell(DAGGERS);
                        if (!player->HasSpell(STAVES))
                            player->learnSpell(STAVES);
                        if (!player->HasSpell(FIST_WEAPONS))
                            player->learnSpell(FIST_WEAPONS);
                        break;
                    case CLASS_HUNTER:
                        if (!player->HasSpell(MAIL))
                            player->learnSpell(MAIL);
                        if (!player->HasSpell(POLEARMS))
                            player->learnSpell(POLEARMS);
                        if (!player->HasSpell(ONE_HANDED_SWORDS))
                            player->learnSpell(ONE_HANDED_SWORDS);
                        if (!player->HasSpell(ONE_HANDED_AXES))
                            player->learnSpell(ONE_HANDED_AXES);
                        if (!player->HasSpell(TWO_HANDED_AXES))
                            player->learnSpell(TWO_HANDED_AXES);
                        if (!player->HasSpell(TWO_HANDED_SWORDS))
                            player->learnSpell(TWO_HANDED_SWORDS);
                        if (!player->HasSpell(DUAL_WIELD))
                            player->learnSpell(DUAL_WIELD);
                        if (!player->HasSpell(DAGGERS))
                            player->learnSpell(DAGGERS);
                        if (!player->HasSpell(STAVES))
                            player->learnSpell(STAVES);
                        if (!player->HasSpell(FIST_WEAPONS))
                            player->learnSpell(FIST_WEAPONS);
                        if (!player->HasSpell(BOWS))
                            player->learnSpell(BOWS);
                        if (!player->HasSpell(CROSSBOWS))
                            player->learnSpell(CROSSBOWS);
                        if (!player->HasSpell(GUNS))
                            player->learnSpell(GUNS);
                        if (!player->HasSpell(PARRY))
                            player->learnSpell(PARRY);
                        break;
                    case CLASS_ROGUE:
                        if (!player->HasSpell(ONE_HANDED_MACES))
                            player->learnSpell(ONE_HANDED_MACES);
                        if (!player->HasSpell(ONE_HANDED_SWORDS))
                            player->learnSpell(ONE_HANDED_SWORDS);
                        if (!player->HasSpell(ONE_HANDED_AXES))
                            player->learnSpell(ONE_HANDED_AXES);
                        if (!player->HasSpell(DUAL_WIELD))
                            player->learnSpell(DUAL_WIELD);
                        if (!player->HasSpell(DAGGERS))
                            player->learnSpell(DAGGERS);
                        if (!player->HasSpell(FIST_WEAPONS))
                            player->learnSpell(FIST_WEAPONS);
                        if (!player->HasSpell(BOWS))
                            player->learnSpell(BOWS);
                        if (!player->HasSpell(CROSSBOWS))
                            player->learnSpell(CROSSBOWS);
                        if (!player->HasSpell(GUNS))
                            player->learnSpell(GUNS);
                        if (!player->HasSpell(PARRY))
                            player->learnSpell(PARRY);
                        break;
                    case CLASS_DEATH_KNIGHT:
                        if (!player->HasSpell(MAIL))
                            player->learnSpell(MAIL);
                        if (!player->HasSpell(PLATE_MAIL))
                            player->learnSpell(PLATE_MAIL);
                        if (!player->HasSpell(POLEARMS))
                            player->learnSpell(POLEARMS);
                        if (!player->HasSpell(ONE_HANDED_MACES))
                            player->learnSpell(ONE_HANDED_MACES);
                        if (!player->HasSpell(TWO_HANDED_MACES))
                            player->learnSpell(TWO_HANDED_MACES);
                        if (!player->HasSpell(ONE_HANDED_SWORDS))
                            player->learnSpell(ONE_HANDED_SWORDS);
                        if (!player->HasSpell(ONE_HANDED_AXES))
                            player->learnSpell(ONE_HANDED_AXES);
                        if (!player->HasSpell(TWO_HANDED_AXES))
                            player->learnSpell(TWO_HANDED_AXES);
                        if (!player->HasSpell(TWO_HANDED_SWORDS))
                            player->learnSpell(TWO_HANDED_SWORDS);
                        if (!player->HasSpell(DUAL_WIELD))
                            player->learnSpell(DUAL_WIELD);
                        if (!player->HasSpell(PARRY))
                            player->learnSpell(PARRY);
                        break;
                }

                if (sConfigMgr->GetBoolDefault("Kickstarter.Proficiency.Max", false))
                    player->UpdateSkillsToMaxSkillsForLevel();

                player->CLOSE_GOSSIP_MENU();
            }

            // Mounts
            if (action == ID_MOUNTS)
            {
                for (int i = 0; i < 5; i++)
                {
                    if (mountSkill[i][2])
                        if (player->getLevel() >= mountSkill[i][1])
                            if (!player->HasSpell(mountSkill[i][0]))
                                player->learnSpell(mountSkill[i][0]);
                }

                for (int i = 0; i < 79; i++)
                {
                    if (player->HasSpell(mountSpell[i][1]))
                        if (player->getRace() == mountSpell[i][2] || (mountSpell[i][2] == 0 && player->GetTeamId() == mountSpell[i][3]))
                            if (!player->HasSpell(mountSpell[i][0]))
                                player->learnSpell(mountSpell[i][0]);
                }

                player->CLOSE_GOSSIP_MENU();
            }

            return true;
        }
};

void AddKickstarterScripts()
{
    new Kickstarter();
}
