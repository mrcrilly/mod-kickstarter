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
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want some equipment", GOSSIP_SENDER_MAIN, ID_EQUIPMENT);

            if (sConfigMgr->GetBoolDefault("Kickstarter.Gems", false))
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want some gems", GOSSIP_SENDER_MAIN, ID_GEMS);

            if (sConfigMgr->GetBoolDefault("Kickstarter.Glyphs", false))
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want some glyphs", GOSSIP_SENDER_MAIN, ID_GLYPHS);

            if (sConfigMgr->GetBoolDefault("Kickstarter.Spells", false))
                AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "I want spells specific to my class", GOSSIP_SENDER_MAIN, ID_SPELLS);

            if (sConfigMgr->GetBoolDefault("Kickstarter.Proficiency", false))
                AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "I want any weapon skills available to me", GOSSIP_SENDER_MAIN, ID_PROFICIENCY);

            if (sConfigMgr->GetBoolDefault("Kickstarter.Mounts", false))
                AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "I want to be able to ride creatures", GOSSIP_SENDER_MAIN, ID_MOUNTS);

            SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
        {
            if (sender != GOSSIP_SENDER_MAIN)
            {
                return false;
            }

            if (action == 1)
            {
                OnGossipHello(player, creature);
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
                            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Remove all my equipment", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+31);
                            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, 1);
                            SendGossipMenuFor(player, TEXT_KICKSTARTER_EQUIPMENT, creature->GetGUID());
                            return false;
                        }
                    }

                    switch (player->getClass())
                    {
                        case CLASS_PRIEST:
                            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Discipline", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+1);
                            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Holy", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+2);
                            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Shadow", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+3);
                            break;
                        case CLASS_PALADIN:
                            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Holy", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+4);
                            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Protection", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+5);
                            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Retribution", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+6);
                            break;
                        case CLASS_WARRIOR:
                            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Arms", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+7);
                            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Fury", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+8);
                            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Protection", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+9);
                            break;
                        case CLASS_MAGE:
                            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Arcane", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+10);
                            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Fire", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+11);
                            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Frost", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+12);
                            break;
                        case CLASS_WARLOCK:
                            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Affliction", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+13);
                            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Demonology", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+14);
                            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Destruction", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+15);
                            break;
                        case CLASS_SHAMAN:
                            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Elemental", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+16);
                            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Enhancement", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+17);
                            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Restoration", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+18);
                            break;
                        case CLASS_DRUID:
                            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Balance", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+19);
                            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Feral Combat", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+20);
                            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Restoration", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+21);
                            break;
                        case CLASS_HUNTER:
                            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Beast Mastery", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+22);
                            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Marksmanship", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+23);
                            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Survival", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+24);
                            break;
                        case CLASS_ROGUE:
                            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Assassination", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+25);
                            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Combat", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+26);
                            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Subtlety", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+27);
                            break;
                        case CLASS_DEATH_KNIGHT:
                            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Blood", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+28);
                            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Frost", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+29);
                            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Unholy", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+30);
                            break;
                        default:
                            break;
                    }

                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, 1);
                    SendGossipMenuFor(player, TEXT_KICKSTARTER_SPECIALIZATION, creature->GetGUID());
                }
                else
                {
                    ClearGossipMenuFor(player);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, 1);
                    SendGossipMenuFor(player, TEXT_KICKSTARTER_LEVEL, creature->GetGUID());
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

                OnGossipHello(player, creature);
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

                OnGossipHello(player, creature);
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

                OnGossipHello(player, creature);
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

                OnGossipHello(player, creature);
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

                OnGossipHello(player, creature);
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

                OnGossipHello(player, creature);
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

                OnGossipHello(player, creature);
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

                OnGossipHello(player, creature);
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

                OnGossipHello(player, creature);
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

                OnGossipHello(player, creature);
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

                OnGossipHello(player, creature);
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

                OnGossipHello(player, creature);
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

                OnGossipHello(player, creature);
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

                OnGossipHello(player, creature);
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

                OnGossipHello(player, creature);
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

                OnGossipHello(player, creature);
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

                OnGossipHello(player, creature);
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

                OnGossipHello(player, creature);
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

                OnGossipHello(player, creature);
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

                OnGossipHello(player, creature);
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

                OnGossipHello(player, creature);
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

                OnGossipHello(player, creature);
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

                OnGossipHello(player, creature);
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

                OnGossipHello(player, creature);
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

                OnGossipHello(player, creature);
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

                OnGossipHello(player, creature);
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

                OnGossipHello(player, creature);
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

                OnGossipHello(player, creature);
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

                OnGossipHello(player, creature);
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

                OnGossipHello(player, creature);
            }

            // Remove equipment
            if (action == ID_EQUIPMENT+31)
            {
                for (int i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
                {
                    if (Item* itemEquipped = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                    {
                        if (itemEquipped)
                        {
                            player->DestroyItemCount(itemEquipped->GetEntry(), 1, true, true);

                            if (itemEquipped->IsInWorld())
                            {
                                itemEquipped->RemoveFromWorld();
                                itemEquipped->DestroyForPlayer(player);
                            }

                            itemEquipped->SetUInt64Value(ITEM_FIELD_CONTAINED, 0);
                            itemEquipped->SetSlot(NULL_SLOT);
                            itemEquipped->SetState(ITEM_REMOVED, player);
                        }
                    }
                }

                OnGossipSelect(player, creature, sender, ID_EQUIPMENT);
            }

            // Gems
            if (action == ID_GEMS)
            {
                ClearGossipMenuFor(player);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "Meta", GOSSIP_SENDER_MAIN, ID_GEMS+1);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "Red", GOSSIP_SENDER_MAIN, ID_GEMS+40);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "Blue", GOSSIP_SENDER_MAIN, ID_GEMS+49);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "Yellow", GOSSIP_SENDER_MAIN, ID_GEMS+54);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "Purple", GOSSIP_SENDER_MAIN, ID_GEMS+61);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "Green", GOSSIP_SENDER_MAIN, ID_GEMS+76);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "Orange", GOSSIP_SENDER_MAIN, ID_GEMS+97);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_TYPE, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+1)
            {
                ClearGossipMenuFor(player);
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "21 Crit Rating, 3% Crit Damage (2 Blue)", GOSSIP_SENDER_MAIN, ID_GEMS+5); // 41285
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "25 Crit Rating, 1% Spell Reflect (1 Red, 1 Yellow, 1 Blue)", GOSSIP_SENDER_MAIN, ID_GEMS+6); // 41307
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "25 Spell Power, 2% Intellect (3 Red)", GOSSIP_SENDER_MAIN, ID_GEMS+7); // 41333
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "21 Crit Rating, 10% Reduced Snare/Root Duration (2 Red, 1 Yellow)", GOSSIP_SENDER_MAIN, ID_GEMS+8); // 41335
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "42 Attack Power, Minor Run Speed (2 Yellow, 1 Red)", GOSSIP_SENDER_MAIN, ID_GEMS+9); // 41339
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "25 Spell Power, Minor Run Speed (1 Red, 1 Blue, 1 Yellow)", GOSSIP_SENDER_MAIN, ID_GEMS+10); // 41375
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "11  Mana 5 Sec, 3% Healing Crit (2 Red)", GOSSIP_SENDER_MAIN, ID_GEMS+11); // 41376
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "32 Stamina, 2% Reduced Spell Damage", GOSSIP_SENDER_MAIN, ID_GEMS+12); // 41377
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "25 Spell Power, 10% Reduced Silence Duration (2 Yellow, 1 Blue)", GOSSIP_SENDER_MAIN, ID_GEMS+13); // 41378
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "21 Crit Rating, 10% Reduced Fear Duration (2 Red, 1 Blue)", GOSSIP_SENDER_MAIN, ID_GEMS+14); // 41379
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Next Page", GOSSIP_SENDER_MAIN, ID_GEMS+2);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, ID_GEMS);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+2)
            {
                ClearGossipMenuFor(player);
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "32 Stamina, 2% Increased Armor Value (2 Blue, 1 Red)", GOSSIP_SENDER_MAIN, ID_GEMS+15); // 41380
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "42 Attack Power, 10% Reduced Stun Duration", GOSSIP_SENDER_MAIN, ID_GEMS+16); // 41381
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "25 Spell Power, 10% Reduced Stun Duration", GOSSIP_SENDER_MAIN, ID_GEMS+17); // 41382
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "42 Attack Power, Sometimes Heal on Crit (2 Blue, 1 Red)", GOSSIP_SENDER_MAIN, ID_GEMS+18); // 41385
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "21 Crit Rating, 2% Mana (2 Red, 1 Yellow)", GOSSIP_SENDER_MAIN, ID_GEMS+19); // 41389
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "25 Spell Power, 2% Reduced Threat (2 Red, 1 Blue)", GOSSIP_SENDER_MAIN, ID_GEMS+20); // 41395
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "21 Defense Rating, 5% Shield Block Value (2 Red, 1 Blue)", GOSSIP_SENDER_MAIN, ID_GEMS+21); // 41396
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "32 Stamina, 10% Reduced Stun Duration (3 Blue)", GOSSIP_SENDER_MAIN, ID_GEMS+22); // 41397
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "21 Agility, 3% Crit Damage", GOSSIP_SENDER_MAIN, ID_GEMS+23); // 41398
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Chance to Increase Attack Speed (1 Red, 1 Yellow, 1 Blue)", GOSSIP_SENDER_MAIN, ID_GEMS+24); // 41400
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Next Page", GOSSIP_SENDER_MAIN, ID_GEMS+3);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, ID_GEMS+1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+3)
            {
                ClearGossipMenuFor(player);
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "21 Intellect, Chance to Restore Mana on Spellcast (1 Red, 1 Yellow, 1 Blue)", GOSSIP_SENDER_MAIN, ID_GEMS+25); // 41401
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "14 Crit Rating, 1% Spell Reflect (2 Red, 2 Blue, 2 Yellow)", GOSSIP_SENDER_MAIN, ID_GEMS+26); // 25890
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Chance to Increase Spell Cast Speed (More Blue than Yellow", GOSSIP_SENDER_MAIN, ID_GEMS+27); // 25893
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "24 Attack Power, Minor Run Speed (2 Yellow, 1 Red)", GOSSIP_SENDER_MAIN, ID_GEMS+28); // 25894
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "12 Crit Rating, 10% Reduced Snare/Root Duration (More Red than Yellow)", GOSSIP_SENDER_MAIN, ID_GEMS+29); // 25895
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "18 Stamina, 15% Reduced Stun Duration (3 Blue)", GOSSIP_SENDER_MAIN, ID_GEMS+30); // 25896
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "14 Spell Power, 2% Reduced Threat (More Red than Blue)", GOSSIP_SENDER_MAIN, ID_GEMS+31); // 25897
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "12 Defense Rating, Chance to restore Health (5 Blue)", GOSSIP_SENDER_MAIN, ID_GEMS+32); // 25898
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "3 Melee Damage, Chance to Stun Target (2 Red, 2 Yellow, 2 Blue)", GOSSIP_SENDER_MAIN, ID_GEMS+33); // 25899
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "12 Intellect, Chance to Restore Mana on Spellcast (2 Red, 2 Yellow, 2 Blue)", GOSSIP_SENDER_MAIN, ID_GEMS+34); // 25901
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Next Page", GOSSIP_SENDER_MAIN, ID_GEMS+4);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, ID_GEMS+2);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+4)
            {
                ClearGossipMenuFor(player);
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "12 Agility, 3% Increased Crit Damage (2 Red, 2 Yellow, 2 Blue)", GOSSIP_SENDER_MAIN, ID_GEMS+35); // 32409
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Chance to Increase Attack Speed (2 Red, 2 Blue, 2 Yellow)", GOSSIP_SENDER_MAIN, ID_GEMS+36); // 32410
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "12 Crit Rating, 3% Increased Crit Damage (2 Blue)", GOSSIP_SENDER_MAIN, ID_GEMS+37); // 34220
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "12 Defense Rating, 5% Shield Block Value (2 Blue, 1 Yellow)", GOSSIP_SENDER_MAIN, ID_GEMS+38); // 35501
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "14 Spell Power, 2% Intellect (3 Red)", GOSSIP_SENDER_MAIN, ID_GEMS+39); // 35503
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, ID_GEMS+3);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+5)
            {
                player->AddItem(41285, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+6)
            {
                player->AddItem(41307, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+7)
            {
                player->AddItem(41333, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+8)
            {
                player->AddItem(41335, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+9)
            {
                player->AddItem(41339, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+10)
            {
                player->AddItem(41375, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+11)
            {
                player->AddItem(41376, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+12)
            {
                player->AddItem(41377, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+13)
            {
                player->AddItem(41378, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+14)
            {
                player->AddItem(41379, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+15)
            {
                player->AddItem(41380, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+16)
            {
                player->AddItem(41381, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+17)
            {
                player->AddItem(41382, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+18)
            {
                player->AddItem(41385, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+19)
            {
                player->AddItem(41389, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+20)
            {
                player->AddItem(41395, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+21)
            {
                player->AddItem(41396, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+22)
            {
                player->AddItem(41397, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+23)
            {
                player->AddItem(41398, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+24)
            {
                player->AddItem(41400, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+25)
            {
                player->AddItem(41401, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+26)
            {
                player->AddItem(25890, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+27)
            {
                player->AddItem(25893, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+28)
            {
                player->AddItem(25894, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+29)
            {
                player->AddItem(25895, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+30)
            {
                player->AddItem(25896, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+31)
            {
                player->AddItem(25897, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+32)
            {
                player->AddItem(25898, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+33)
            {
                player->AddItem(25899, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+34)
            {
                player->AddItem(25901, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+35)
            {
                player->AddItem(32409, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+36)
            {
                player->AddItem(32410, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+37)
            {
                player->AddItem(34220, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+38)
            {
                player->AddItem(35501, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+39)
            {
                player->AddItem(35503, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Red
            if (action == ID_GEMS+40)
            {
                ClearGossipMenuFor(player);
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "20 Strength", GOSSIP_SENDER_MAIN, ID_GEMS+41); // 40111
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "20 Agility", GOSSIP_SENDER_MAIN, ID_GEMS+42); // 40112
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "23 Spell Power", GOSSIP_SENDER_MAIN, ID_GEMS+43); // 40113
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "40 Attack Power", GOSSIP_SENDER_MAIN, ID_GEMS+44); // 40114
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "20 Dodge Rating", GOSSIP_SENDER_MAIN, ID_GEMS+45); // 40115
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "20 Parry Rating", GOSSIP_SENDER_MAIN, ID_GEMS+46); // 40116
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "20 Armor Penetration Rating", GOSSIP_SENDER_MAIN, ID_GEMS+47); // 40117
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "20 Expertise Rating", GOSSIP_SENDER_MAIN, ID_GEMS+48); // 40118
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, ID_GEMS);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Red
            if (action == ID_GEMS+41)
            {
                player->AddItem(40111, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Red
            if (action == ID_GEMS+42)
            {
                player->AddItem(40112, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Red
            if (action == ID_GEMS+43)
            {
                player->AddItem(40113, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Red
            if (action == ID_GEMS+44)
            {
                player->AddItem(40114, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Red
            if (action == ID_GEMS+45)
            {
                player->AddItem(40115, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Red
            if (action == ID_GEMS+46)
            {
                player->AddItem(40116, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Red
            if (action == ID_GEMS+47)
            {
                player->AddItem(40117, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Red
            if (action == ID_GEMS+48)
            {
                player->AddItem(40118, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Blue
            if (action == ID_GEMS+49)
            {
                ClearGossipMenuFor(player);
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "30 Stamina", GOSSIP_SENDER_MAIN, ID_GEMS+50); // 40119
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "20 Spirit", GOSSIP_SENDER_MAIN, ID_GEMS+51); // 40120
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Mana every 5 Seconds", GOSSIP_SENDER_MAIN, ID_GEMS+52); // 40121
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "25 Spell Penetration", GOSSIP_SENDER_MAIN, ID_GEMS+53); // 40122
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, ID_GEMS);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Blue
            if (action == ID_GEMS+50)
            {
                player->AddItem(40119, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Blue
            if (action == ID_GEMS+51)
            {
                player->AddItem(40120, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Blue
            if (action == ID_GEMS+52)
            {
                player->AddItem(40121, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Blue
            if (action == ID_GEMS+53)
            {
                player->AddItem(40122, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Yellow
            if (action == ID_GEMS+54)
            {
                ClearGossipMenuFor(player);
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "20 Intellect", GOSSIP_SENDER_MAIN, ID_GEMS+55); // 40123
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "20 Critical Strike Rating", GOSSIP_SENDER_MAIN, ID_GEMS+56); // 40124
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "20 Hit Rating", GOSSIP_SENDER_MAIN, ID_GEMS+57); // 40125
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "20 Defense Rating", GOSSIP_SENDER_MAIN, ID_GEMS+58); // 40126
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "20 Resilience Rating", GOSSIP_SENDER_MAIN, ID_GEMS+59); // 40127
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "20 Haste Rating", GOSSIP_SENDER_MAIN, ID_GEMS+60); // 40128
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, ID_GEMS);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Yellow
            if (action == ID_GEMS+55)
            {
                player->AddItem(40123, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Yellow
            if (action == ID_GEMS+56)
            {
                player->AddItem(40124, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Yellow
            if (action == ID_GEMS+57)
            {
                player->AddItem(40125, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Yellow
            if (action == ID_GEMS+58)
            {
                player->AddItem(40126, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Yellow
            if (action == ID_GEMS+59)
            {
                player->AddItem(40127, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Yellow
            if (action == ID_GEMS+60)
            {
                player->AddItem(40128, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Purple
            if (action == ID_GEMS+61)
            {
                ClearGossipMenuFor(player);
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Strength, 15 Stamina", GOSSIP_SENDER_MAIN, ID_GEMS+63); // 40129
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Agility, 15 Stamina", GOSSIP_SENDER_MAIN, ID_GEMS+64); // 40130
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Agility, 5 Mana per 5 Seconds", GOSSIP_SENDER_MAIN, ID_GEMS+65); // 40131
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "12 Spell Power, 15 Stamina", GOSSIP_SENDER_MAIN, ID_GEMS+66); // 40132
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "12 Spell Power, 10 Spirit", GOSSIP_SENDER_MAIN, ID_GEMS+67); // 40133
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "12 Spell Power, 5 Mana per 5 Seconds", GOSSIP_SENDER_MAIN, ID_GEMS+68); // 40134
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "12 Spell Power, 13 Spell Penetration", GOSSIP_SENDER_MAIN, ID_GEMS+69); // 40135
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "20 Attack Power, 15 Stamina", GOSSIP_SENDER_MAIN, ID_GEMS+70); // 40136
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "20 Attack Power, 5 Mana per 5 Seconds", GOSSIP_SENDER_MAIN, ID_GEMS+71); // 40137
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Dodge Rating, 15 Stamina", GOSSIP_SENDER_MAIN, ID_GEMS+72); // 40138
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Next Page", GOSSIP_SENDER_MAIN, ID_GEMS+62);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, ID_GEMS);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Purple
            if (action == ID_GEMS+62)
            {
                ClearGossipMenuFor(player);
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Parry Rating, 15 Stamina", GOSSIP_SENDER_MAIN, ID_GEMS+73); // 40139
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Armor Penetration, 15 Stamina", GOSSIP_SENDER_MAIN, ID_GEMS+74); // 40140
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Expertise Rating, 15 Stamina", GOSSIP_SENDER_MAIN, ID_GEMS+75); // 40141
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, ID_GEMS+61);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Purple
            if (action == ID_GEMS+63)
            {
                player->AddItem(40129, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Purple
            if (action == ID_GEMS+64)
            {
                player->AddItem(40130, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Purple
            if (action == ID_GEMS+65)
            {
                player->AddItem(40131, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Purple
            if (action == ID_GEMS+66)
            {
                player->AddItem(40132, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Purple
            if (action == ID_GEMS+67)
            {
                player->AddItem(40133, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Purple
            if (action == ID_GEMS+68)
            {
                player->AddItem(40134, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Purple
            if (action == ID_GEMS+69)
            {
                player->AddItem(40135, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Purple
            if (action == ID_GEMS+70)
            {
                player->AddItem(40136, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Purple
            if (action == ID_GEMS+71)
            {
                player->AddItem(40137, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Purple
            if (action == ID_GEMS+72)
            {
                player->AddItem(40138, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Purple
            if (action == ID_GEMS+73)
            {
                player->AddItem(40139, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Purple
            if (action == ID_GEMS+74)
            {
                player->AddItem(40140, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Purple
            if (action == ID_GEMS+75)
            {
                player->AddItem(40141, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Green
            if (action == ID_GEMS+76)
            {
                ClearGossipMenuFor(player);
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Intellect, 15 Stamina", GOSSIP_SENDER_MAIN, ID_GEMS+78); // 40164
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Critical Strike Rating, 15 Stamina", GOSSIP_SENDER_MAIN, ID_GEMS+79); // 40165
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Hit Rating, 15 Stamina", GOSSIP_SENDER_MAIN, ID_GEMS+80); // 40166
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Defense Rating, 15 Stamina", GOSSIP_SENDER_MAIN, ID_GEMS+81); // 40167
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Resilience Rating, 15 Stamina", GOSSIP_SENDER_MAIN, ID_GEMS+82); // 40168
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Haste Rating, 15 Stamina", GOSSIP_SENDER_MAIN, ID_GEMS+83); // 40169
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Intellect, 10 Spirit", GOSSIP_SENDER_MAIN, ID_GEMS+84); // 40170
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Critical Strike Rating, 10 Spirit", GOSSIP_SENDER_MAIN, ID_GEMS+85); // 40171
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Hit Rating, 10 Spirit", GOSSIP_SENDER_MAIN, ID_GEMS+86); // 40172
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Resilience Rating, 10 Spirit", GOSSIP_SENDER_MAIN, ID_GEMS+87); // 40173
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Next Page", GOSSIP_SENDER_MAIN, ID_GEMS+77);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, ID_GEMS);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Green
            if (action == ID_GEMS+77)
            {
                ClearGossipMenuFor(player);
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Haste Rating, 10 Spirit", GOSSIP_SENDER_MAIN, ID_GEMS+88); // 40174
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Intellect, 5 Mana per 5 Seconds", GOSSIP_SENDER_MAIN, ID_GEMS+89); // 40175
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Critical Strike Rating, 5 Mana per 5 Seconds", GOSSIP_SENDER_MAIN, ID_GEMS+90); // 40176
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Hit Rating, 5 Mana per 5 Seconds", GOSSIP_SENDER_MAIN, ID_GEMS+91); // 40177
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Resilience Rating, 5 Mana per 5 Seconds", GOSSIP_SENDER_MAIN, ID_GEMS+92); // 40178
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Haste Rating, 5 Mana per 5 Seconds", GOSSIP_SENDER_MAIN, ID_GEMS+93); // 40179
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Critical Strike Rating, 13 Spell Penetration", GOSSIP_SENDER_MAIN, ID_GEMS+94); // 40180
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Hit Rating, 13 Spell Penetration", GOSSIP_SENDER_MAIN, ID_GEMS+95); // 40181
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Haste Rating, 13 Spell Penetration", GOSSIP_SENDER_MAIN, ID_GEMS+96); // 40182
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, ID_GEMS+76);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Green
            if (action == ID_GEMS+78)
            {
                player->AddItem(40164, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Green
            if (action == ID_GEMS+79)
            {
                player->AddItem(40165, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Green
            if (action == ID_GEMS+80)
            {
                player->AddItem(40166, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Green
            if (action == ID_GEMS+81)
            {
                player->AddItem(40167, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Green
            if (action == ID_GEMS+82)
            {
                player->AddItem(40168, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Green
            if (action == ID_GEMS+83)
            {
                player->AddItem(40169, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Green
            if (action == ID_GEMS+84)
            {
                player->AddItem(40170, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Green
            if (action == ID_GEMS+85)
            {
                player->AddItem(40171, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Green
            if (action == ID_GEMS+86)
            {
                player->AddItem(40172, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Green
            if (action == ID_GEMS+87)
            {
                player->AddItem(40173, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Green
            if (action == ID_GEMS+88)
            {
                player->AddItem(40174, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Green
            if (action == ID_GEMS+89)
            {
                player->AddItem(40175, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Green
            if (action == ID_GEMS+90)
            {
                player->AddItem(40176, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Green
            if (action == ID_GEMS+91)
            {
                player->AddItem(40177, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Green
            if (action == ID_GEMS+92)
            {
                player->AddItem(40178, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Green
            if (action == ID_GEMS+93)
            {
                player->AddItem(40179, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Green
            if (action == ID_GEMS+94)
            {
                player->AddItem(40180, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Green
            if (action == ID_GEMS+95)
            {
                player->AddItem(40181, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Green
            if (action == ID_GEMS+96)
            {
                player->AddItem(40182, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Orange
            if (action == ID_GEMS+97)
            {
                ClearGossipMenuFor(player);
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Strength, 10 Critical Strike Rating", GOSSIP_SENDER_MAIN, ID_GEMS+100); // 40142
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Strength, 10 Hit Rating", GOSSIP_SENDER_MAIN, ID_GEMS+101); // 40143
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Strength, 10 Defense Rating", GOSSIP_SENDER_MAIN, ID_GEMS+102); // 40144
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Strength, 10 Resilience Rating", GOSSIP_SENDER_MAIN, ID_GEMS+103); // 40145
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Strength, 10 Haste Rating", GOSSIP_SENDER_MAIN, ID_GEMS+104); // 40146
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Agility, 10 Critical Strike Rating", GOSSIP_SENDER_MAIN, ID_GEMS+105); // 40147
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Agility, 10 Hit rating", GOSSIP_SENDER_MAIN, ID_GEMS+106); // 40148
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Agility, 10 Resilience Rating", GOSSIP_SENDER_MAIN, ID_GEMS+107); // 40149
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Agility, 10 Haste Rating", GOSSIP_SENDER_MAIN, ID_GEMS+108); // 40150
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "12 Spell Power, 10 Intellect", GOSSIP_SENDER_MAIN, ID_GEMS+109); // 40151
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Next Page", GOSSIP_SENDER_MAIN, ID_GEMS+98);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, ID_GEMS);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Orange
            if (action == ID_GEMS+98)
            {
                ClearGossipMenuFor(player);
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "12 Spell Power, 10 Critical Strike Rating", GOSSIP_SENDER_MAIN, ID_GEMS+110); // 40152
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "12 Spell Power, 10 Hit Rating", GOSSIP_SENDER_MAIN, ID_GEMS+111); // 40153
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "12 Spell Power, 10 Resilience Rating", GOSSIP_SENDER_MAIN, ID_GEMS+112); // 40154
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "12 Spell Power, 10 Haste Rating", GOSSIP_SENDER_MAIN, ID_GEMS+113); // 40155
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "20 Attack Power, 10 Critical Strike Rating", GOSSIP_SENDER_MAIN, ID_GEMS+114); // 40156
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "20 Attack Power, 10 Hit Rating", GOSSIP_SENDER_MAIN, ID_GEMS+115); // 40157
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "20 Attack Power, 10 Resilience Rating", GOSSIP_SENDER_MAIN, ID_GEMS+116); // 40158
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "20 Attack Power, 10 Haste Rating", GOSSIP_SENDER_MAIN, ID_GEMS+117); // 40159
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Dodge Rating, 10 Defense Rating", GOSSIP_SENDER_MAIN, ID_GEMS+118); // 40160
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Parry Rating, 10 Defense Rating", GOSSIP_SENDER_MAIN, ID_GEMS+119); // 40161
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Next Page", GOSSIP_SENDER_MAIN, ID_GEMS+99);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, ID_GEMS+97);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Orange
            if (action == ID_GEMS+99)
            {
                ClearGossipMenuFor(player);
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Expertise Rating, 10 Hit Rating", GOSSIP_SENDER_MAIN, ID_GEMS+120); // 40162
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "10 Expertise Rating, 10 Defense Rating", GOSSIP_SENDER_MAIN, ID_GEMS+121); // 40163
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, ID_GEMS+98);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Orange
            if (action == ID_GEMS+100)
            {
                player->AddItem(40142, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Orange
            if (action == ID_GEMS+101)
            {
                player->AddItem(40143, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Orange
            if (action == ID_GEMS+102)
            {
                player->AddItem(40144, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Orange
            if (action == ID_GEMS+103)
            {
                player->AddItem(40145, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Orange
            if (action == ID_GEMS+104)
            {
                player->AddItem(40146, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Orange
            if (action == ID_GEMS+105)
            {
                player->AddItem(40147, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Orange
            if (action == ID_GEMS+106)
            {
                player->AddItem(40148, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Orange
            if (action == ID_GEMS+107)
            {
                player->AddItem(40149, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Orange
            if (action == ID_GEMS+108)
            {
                player->AddItem(40150, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Orange
            if (action == ID_GEMS+109)
            {
                player->AddItem(40151, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Orange
            if (action == ID_GEMS+110)
            {
                player->AddItem(40152, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Orange
            if (action == ID_GEMS+111)
            {
                player->AddItem(40153, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Orange
            if (action == ID_GEMS+112)
            {
                player->AddItem(40154, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Orange
            if (action == ID_GEMS+113)
            {
                player->AddItem(40155, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Orange
            if (action == ID_GEMS+114)
            {
                player->AddItem(40156, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Orange
            if (action == ID_GEMS+115)
            {
                player->AddItem(40157, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Orange
            if (action == ID_GEMS+116)
            {
                player->AddItem(40158, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Orange
            if (action == ID_GEMS+117)
            {
                player->AddItem(40159, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Orange
            if (action == ID_GEMS+118)
            {
                player->AddItem(40160, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Orange
            if (action == ID_GEMS+119)
            {
                player->AddItem(40161, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Orange
            if (action == ID_GEMS+120)
            {
                player->AddItem(40162, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Orange
            if (action == ID_GEMS+121)
            {
                player->AddItem(40163, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs
            if (action == ID_GLYPHS)
            {
                ClearGossipMenuFor(player);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "Major", GOSSIP_SENDER_MAIN, ID_GLYPHS+1);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "Minor", GOSSIP_SENDER_MAIN, ID_GLYPHS+5);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_TYPE, creature->GetGUID());
            }

            // Glyphs: Major
            if (action == ID_GLYPHS+1)
            {
                ClearGossipMenuFor(player);

                switch (player->getClass())
                {
                    case CLASS_PRIEST:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Mass Dispel", GOSSIP_SENDER_MAIN, ID_GLYPHS+6); // 42404
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Shadow Word: Death", GOSSIP_SENDER_MAIN, ID_GLYPHS+7); // 42414
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Circle of Healing", GOSSIP_SENDER_MAIN, ID_GLYPHS+8); // 42396
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Lightwell", GOSSIP_SENDER_MAIN, ID_GLYPHS+9); // 42403
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Dispersion", GOSSIP_SENDER_MAIN, ID_GLYPHS+10); // 45753
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Guardian Spirit", GOSSIP_SENDER_MAIN, ID_GLYPHS+11); // 45755
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Penance", GOSSIP_SENDER_MAIN, ID_GLYPHS+12); // 45756
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Mind Sear", GOSSIP_SENDER_MAIN, ID_GLYPHS+13); // 45757
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Hymn of Hope", GOSSIP_SENDER_MAIN, ID_GLYPHS+14); // 45758
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Pain Suppression", GOSSIP_SENDER_MAIN, ID_GLYPHS+15); // 45760
                        break;
                    case CLASS_PALADIN:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Avenging Wrath", GOSSIP_SENDER_MAIN, ID_GLYPHS+16); // 41107
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Avenger's Shield", GOSSIP_SENDER_MAIN, ID_GLYPHS+17); // 41101
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Holy Wrath", GOSSIP_SENDER_MAIN, ID_GLYPHS+18); // 43867
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Seal of Righteousness", GOSSIP_SENDER_MAIN, ID_GLYPHS+19); // 43868
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Seal of Vengeance", GOSSIP_SENDER_MAIN, ID_GLYPHS+20); // 43869
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Hammer of Wrath", GOSSIP_SENDER_MAIN, ID_GLYPHS+21); // 41097
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Beacon of Light", GOSSIP_SENDER_MAIN, ID_GLYPHS+22); // 45741
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Hammer of the Righteous", GOSSIP_SENDER_MAIN, ID_GLYPHS+23); // 45742
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Divine Storm", GOSSIP_SENDER_MAIN, ID_GLYPHS+24); // 45743
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Shield of Righteousness", GOSSIP_SENDER_MAIN, ID_GLYPHS+25); // 45744
                        break;
                    case CLASS_WARRIOR:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Intervene", GOSSIP_SENDER_MAIN, ID_GLYPHS+26); // 43419
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Devastate", GOSSIP_SENDER_MAIN, ID_GLYPHS+27); // 43415
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Bladestorm", GOSSIP_SENDER_MAIN, ID_GLYPHS+28); // 45790
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Shockwave", GOSSIP_SENDER_MAIN, ID_GLYPHS+29); // 45792
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Vigilance", GOSSIP_SENDER_MAIN, ID_GLYPHS+30); // 45793
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Enraged Regeneration", GOSSIP_SENDER_MAIN, ID_GLYPHS+31); // 45794
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Spell Reflection", GOSSIP_SENDER_MAIN, ID_GLYPHS+32); // 45795
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Shield Wall", GOSSIP_SENDER_MAIN, ID_GLYPHS+33); // 45797
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Bloodthirst", GOSSIP_SENDER_MAIN, ID_GLYPHS+34); // 43412
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Mortal Strike", GOSSIP_SENDER_MAIN, ID_GLYPHS+35); // 43421
                        break;
                    case CLASS_MAGE:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Frostfire", GOSSIP_SENDER_MAIN, ID_GLYPHS+36); // 44684
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Invisibility", GOSSIP_SENDER_MAIN, ID_GLYPHS+37); // 42748
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Ice Lance", GOSSIP_SENDER_MAIN, ID_GLYPHS+38); // 42745
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Molten Armor", GOSSIP_SENDER_MAIN, ID_GLYPHS+39); // 42751
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Arcane Blast", GOSSIP_SENDER_MAIN, ID_GLYPHS+40); // 44955
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Water Elemental", GOSSIP_SENDER_MAIN, ID_GLYPHS+41); // 42754
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Eternal Water", GOSSIP_SENDER_MAIN, ID_GLYPHS+42); // 50045
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Arcane Power", GOSSIP_SENDER_MAIN, ID_GLYPHS+43); // 42736
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Deep Freeze", GOSSIP_SENDER_MAIN, ID_GLYPHS+44); // 45736
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Living Bomb", GOSSIP_SENDER_MAIN, ID_GLYPHS+45); // 45737
                        break;
                    case CLASS_WARLOCK:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Felguard", GOSSIP_SENDER_MAIN, ID_GLYPHS+46); // 42459
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Unstable Affliction", GOSSIP_SENDER_MAIN, ID_GLYPHS+47); // 42472
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Death Coil", GOSSIP_SENDER_MAIN, ID_GLYPHS+48); // 42457
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Conflagrate", GOSSIP_SENDER_MAIN, ID_GLYPHS+49); // 42454
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Howl of Terror", GOSSIP_SENDER_MAIN, ID_GLYPHS+50); // 42463
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Haunt", GOSSIP_SENDER_MAIN, ID_GLYPHS+51); // 45779
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Metamorphosis", GOSSIP_SENDER_MAIN, ID_GLYPHS+52); // 45780
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Chaos Bolt", GOSSIP_SENDER_MAIN, ID_GLYPHS+53); // 45781
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Demonic Circle", GOSSIP_SENDER_MAIN, ID_GLYPHS+54); // 45782
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Shadowflame", GOSSIP_SENDER_MAIN, ID_GLYPHS+55); // 45783
                        break;
                    case CLASS_SHAMAN:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Fire Elemental Totem", GOSSIP_SENDER_MAIN, ID_GLYPHS+56); // 41529
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Lava", GOSSIP_SENDER_MAIN, ID_GLYPHS+57); // 41524
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Elemental Mastery", GOSSIP_SENDER_MAIN, ID_GLYPHS+58); // 41552
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Chain Heal", GOSSIP_SENDER_MAIN, ID_GLYPHS+59); // 41517
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Mana Tide Totem", GOSSIP_SENDER_MAIN, ID_GLYPHS+60); // 41538
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Stormstrike", GOSSIP_SENDER_MAIN, ID_GLYPHS+61); // 41539
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Thunder", GOSSIP_SENDER_MAIN, ID_GLYPHS+62); // 45770
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Feral Spirit", GOSSIP_SENDER_MAIN, ID_GLYPHS+63); // 45771
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Riptide", GOSSIP_SENDER_MAIN, ID_GLYPHS+64); // 45772
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Earth Shield", GOSSIP_SENDER_MAIN, ID_GLYPHS+65); // 45775
                        break;
                    case CLASS_DRUID:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Lifebloom", GOSSIP_SENDER_MAIN, ID_GLYPHS+66); // 40915
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Focus", GOSSIP_SENDER_MAIN, ID_GLYPHS+67); // 44928
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Starfall", GOSSIP_SENDER_MAIN, ID_GLYPHS+68); // 40921
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Mangle", GOSSIP_SENDER_MAIN, ID_GLYPHS+69); // 40900
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Swiftmend", GOSSIP_SENDER_MAIN, ID_GLYPHS+70); // 40906
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Innervate", GOSSIP_SENDER_MAIN, ID_GLYPHS+71); // 40908
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Hurricane", GOSSIP_SENDER_MAIN, ID_GLYPHS+72); // 40920
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Berserk", GOSSIP_SENDER_MAIN, ID_GLYPHS+73); // 45601
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Wild Growth", GOSSIP_SENDER_MAIN, ID_GLYPHS+74); // 45602
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Nourish", GOSSIP_SENDER_MAIN, ID_GLYPHS+75); // 45603
                        break;
                    case CLASS_HUNTER:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Snake Trap", GOSSIP_SENDER_MAIN, ID_GLYPHS+76); // 42913
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Steady Shot", GOSSIP_SENDER_MAIN, ID_GLYPHS+77); // 42914
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Bestial Wrath", GOSSIP_SENDER_MAIN, ID_GLYPHS+78); // 42902
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Trueshot Aura", GOSSIP_SENDER_MAIN, ID_GLYPHS+79); // 42915
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Volley", GOSSIP_SENDER_MAIN, ID_GLYPHS+80); // 42916
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Wyvern Sting", GOSSIP_SENDER_MAIN, ID_GLYPHS+81); // 42917
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Chimera Shot", GOSSIP_SENDER_MAIN, ID_GLYPHS+82); // 45625
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Explosive Shot", GOSSIP_SENDER_MAIN, ID_GLYPHS+83); // 45731
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Kill Shot", GOSSIP_SENDER_MAIN, ID_GLYPHS+84); // 45732
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Explosive Trap", GOSSIP_SENDER_MAIN, ID_GLYPHS+85); // 45733
                        break;
                    case CLASS_ROGUE:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Vigor", GOSSIP_SENDER_MAIN, ID_GLYPHS+86); // 42971
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Deadly Throw", GOSSIP_SENDER_MAIN, ID_GLYPHS+87); // 42959
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Adrenaline Rush", GOSSIP_SENDER_MAIN, ID_GLYPHS+88); // 42954
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Hunger for Blood", GOSSIP_SENDER_MAIN, ID_GLYPHS+89); // 45761
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Killing Spree", GOSSIP_SENDER_MAIN, ID_GLYPHS+90); // 45762
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Shadow Dance", GOSSIP_SENDER_MAIN, ID_GLYPHS+91); // 45764
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Fan of Knives", GOSSIP_SENDER_MAIN, ID_GLYPHS+92); // 45766
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Tricks of the Trade", GOSSIP_SENDER_MAIN, ID_GLYPHS+93); // 45767
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Mutilate", GOSSIP_SENDER_MAIN, ID_GLYPHS+94); // 45768
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Cloak of Shadows", GOSSIP_SENDER_MAIN, ID_GLYPHS+95); // 45769
                        break;
                    case CLASS_DEATH_KNIGHT:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Anti-Magic Shell", GOSSIP_SENDER_MAIN, ID_GLYPHS+96); // 43533
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Heart Strike", GOSSIP_SENDER_MAIN, ID_GLYPHS+97); // 43534
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Bone Shield", GOSSIP_SENDER_MAIN, ID_GLYPHS+98); // 43536
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Chains of Ice", GOSSIP_SENDER_MAIN, ID_GLYPHS+99); // 43537
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Dark Command", GOSSIP_SENDER_MAIN, ID_GLYPHS+100); // 43538
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Death Grip", GOSSIP_SENDER_MAIN, ID_GLYPHS+101); // 43541
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Death and Decay", GOSSIP_SENDER_MAIN, ID_GLYPHS+102); // 43542
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Frost Strike", GOSSIP_SENDER_MAIN, ID_GLYPHS+103); // 43543
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Icebound Fortitude", GOSSIP_SENDER_MAIN, ID_GLYPHS+104); // 43545
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Icy Touch", GOSSIP_SENDER_MAIN, ID_GLYPHS+105); // 43546
                        break;
                    default:
                        break;
                }

                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Next Page", GOSSIP_SENDER_MAIN, ID_GLYPHS+2);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, ID_GLYPHS);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major
            if (action == ID_GLYPHS+2)
            {
                ClearGossipMenuFor(player);

                switch (player->getClass())
                {
                    case CLASS_PRIEST:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+106); // 42405
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+107); // 42409
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+108); // 42417
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+109); // 42399
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+110); // 42400
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+111); // 42401
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+112); // 42407
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+113); // 42412
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+114); // 42397
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+115); // 42415
                        break;
                    case CLASS_PALADIN:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+116); // 45745
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+117); // 45746
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+118); // 45747
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+119); // 41109
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+120); // 41104
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+121); // 41110
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+122); // 41102
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+123); // 41094
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+124); // 41098
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+125); // 41099
                        break;
                    case CLASS_WARRIOR:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+126); // 43425
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+127); // 43432
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+128); // 43428
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+129); // 43416
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+130); // 43414
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+131); // 43426
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+132); // 43420
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+133); // 43431
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+134); // 43424
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+135); // 43422
                        break;
                    case CLASS_MAGE:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+136); // 45738
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+137); // 45739
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+138); // 45740
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+139); // 42749
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+140); // 42744
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+141); // 42750
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+142); // 42737
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+143); // 42738
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+144); // 42746
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+145); // 42747
                        break;
                    case CLASS_WARLOCK:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+146); // 45785
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+147); // 45789
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+148); // 42460
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+149); // 42469
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+150); // 42453
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+151); // 42471
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+152); // 42468
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+153); // 42466
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+154); // 42470
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+155); // 42461
                        break;
                    case CLASS_SHAMAN:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+156); // 45776
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+157); // 45777
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+158); // 45778
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+159); // 41518
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+160); // 41527
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+161); // 41542
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+162); // 41533
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+163); // 41535
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+164); // 41541
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+165); // 41547
                        break;
                    case CLASS_DRUID:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+166); // 45604
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+167); // 45622
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+168); // 45623
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+169); // 40896
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+170); // 40903
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+171); // 40901
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+172); // 40902
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+173); // 40909
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+174); // 40916
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+175); // 40919
                        break;
                    case CLASS_HUNTER:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+176); // 45734
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+177); // 45735
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+178); // 42899
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+179); // 42906
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+180); // 42911
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+181); // 42897
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+182); // 42903
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+183); // 42904
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+184); // 42905
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+185); // 42910
                        break;
                    case CLASS_ROGUE:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+186); // 45908
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+187); // 42957
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+188); // 42967
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+189); // 42968
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+190); // 42958
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+191); // 42965
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+192); // 42969
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+193); // 42955
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+194); // 42963
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+195); // 42962
                        break;
                    case CLASS_DEATH_KNIGHT:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+196); // 43547
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+197); // 43548
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+198); // 43549
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+199); // 43550
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+200); // 43551
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+201); // 43552
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+202); // 43553
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+203); // 43554
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+204); // 43825
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+205); // 43826
                        break;
                    default:
                        break;
                }

                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Next Page", GOSSIP_SENDER_MAIN, ID_GLYPHS+3);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, ID_GLYPHS+1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major
            if (action == ID_GLYPHS+3)
            {
                ClearGossipMenuFor(player);

                switch (player->getClass())
                {
                    case CLASS_PRIEST:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+206); // 42410
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+207); // 42402
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+208); // 42406
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+209); // 42398
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+210); // 42411
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+211); // 42408
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+212); // 42416
                        break;
                    case CLASS_PALADIN:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+213); // 41103
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+214); // 41105
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+215); // 41100
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+216); // 41096
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+217); // 41108
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+218); // 41095
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+219); // 41092
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+220); // 41106
                        break;
                    case CLASS_WARRIOR:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+221); // 43427
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+222); // 43429
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+223); // 43417
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+224); // 43430
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+225); // 43413
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+226); // 43423
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+227); // 43418
                        break;
                    case CLASS_MAGE:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+228); // 42753
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+229); // 42734
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+230); // 42741
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+231); // 42743
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+232); // 42735
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+233); // 42752
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+234); // 42740
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+235); // 42742
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+236); // 42739
                        break;
                    case CLASS_WARLOCK:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+237); // 42455
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+238); // 42462
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+239); // 42473
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+240); // 50077
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+241); // 42456
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+242); // 42458
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+243); // 42465
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+244); // 42464
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+245); // 42467
                        break;
                    case CLASS_SHAMAN:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+246); // 41530
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+247); // 41531
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+248); // 41532
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+249); // 41540
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+250); // 41537
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+251); // 41526
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+252); // 41534
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+253); // 41536
                        break;
                    case CLASS_DRUID:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+254); // 46372
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+255); // 48720
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+256); // 40912
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+257); // 40899
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+258); // 40923
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+259); // 40897
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+260); // 40914
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+261); // 40924
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+262); // 40913
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+263); // 50125
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Next Page", GOSSIP_SENDER_MAIN, ID_GLYPHS+4);
                        break;
                    case CLASS_HUNTER:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+264); // 42908
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+265); // 42901
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+266); // 42909
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+267); // 42898
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+268); // 42907
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+269); // 42900
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+270); // 42912
                        break;
                    case CLASS_ROGUE:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+271); // 42964
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+272); // 42970
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+273); // 42973
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+274); // 42974
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+275); // 42960
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+276); // 42966
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+277); // 42956
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+278); // 42961
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+279); // 42972
                        break;
                    case CLASS_DEATH_KNIGHT:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+280); // 43827
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+281); // 45799
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+282); // 45800
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+283); // 45803
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+284); // 45804
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+285); // 45805
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of ", GOSSIP_SENDER_MAIN, ID_GLYPHS+286); // 45806
                        break;
                    default:
                        break;
                }
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, ID_GLYPHS+2);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major
            if (action == ID_GLYPHS+4)
            {
                ClearGossipMenuFor(player);

                switch (player->getClass())
                {
                    case CLASS_DRUID:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Wrath", GOSSIP_SENDER_MAIN, ID_GLYPHS+287); // 40922
                        break;
                    default:
                        break;
                }

                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, ID_GLYPHS+3);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor
            if (action == ID_GLYPHS+5)
            {
                ClearGossipMenuFor(player);

                switch (player->getClass())
                {
                    case CLASS_PRIEST:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Shadowfiend", GOSSIP_SENDER_MAIN, ID_GLYPHS+287); // 43374
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Levitate", GOSSIP_SENDER_MAIN, ID_GLYPHS+288); // 43370
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Shadow Protection", GOSSIP_SENDER_MAIN, ID_GLYPHS+289); // 43372
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Shackle Undead", GOSSIP_SENDER_MAIN, ID_GLYPHS+290); // 43373
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Fading", GOSSIP_SENDER_MAIN, ID_GLYPHS+291); // 43342
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Fortitude", GOSSIP_SENDER_MAIN, ID_GLYPHS+292); // 43371
                        break;
                    case CLASS_PALADIN:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of the Wise", GOSSIP_SENDER_MAIN, ID_GLYPHS+293); // 43369
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Blessing of Kings", GOSSIP_SENDER_MAIN, ID_GLYPHS+294); // 43365
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Sense Undead", GOSSIP_SENDER_MAIN, ID_GLYPHS+295); // 43368
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Blessing of Wisdom", GOSSIP_SENDER_MAIN, ID_GLYPHS+296); // 43366
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Lay on Hands", GOSSIP_SENDER_MAIN, ID_GLYPHS+297); // 43367
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Blessing of Might", GOSSIP_SENDER_MAIN, ID_GLYPHS+298); // 43340
                        break;
                    case CLASS_WARRIOR:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Command", GOSSIP_SENDER_MAIN, ID_GLYPHS+299); // 49084
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Enduring Victory", GOSSIP_SENDER_MAIN, ID_GLYPHS+300); // 43400
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Mocking Blow", GOSSIP_SENDER_MAIN, ID_GLYPHS+301); // 43398
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Bloodrage", GOSSIP_SENDER_MAIN, ID_GLYPHS+302); // 43396
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Thunder Clap", GOSSIP_SENDER_MAIN, ID_GLYPHS+303); // 43399
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Charge", GOSSIP_SENDER_MAIN, ID_GLYPHS+304); // 43397
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Battle", GOSSIP_SENDER_MAIN, ID_GLYPHS+305); // 43395
                        break;
                    case CLASS_MAGE:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Blast Wave", GOSSIP_SENDER_MAIN, ID_GLYPHS+306); // 44920
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Frost Ward", GOSSIP_SENDER_MAIN, ID_GLYPHS+307); // 43360
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Fire Ward", GOSSIP_SENDER_MAIN, ID_GLYPHS+308); // 43357
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Slow Fall", GOSSIP_SENDER_MAIN, ID_GLYPHS+309); // 43364
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of the Penguin", GOSSIP_SENDER_MAIN, ID_GLYPHS+310); // 43361
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of the Bear Cub", GOSSIP_SENDER_MAIN, ID_GLYPHS+311); // 43362
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Arcane Intellect", GOSSIP_SENDER_MAIN, ID_GLYPHS+312); // 43339
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Frost Armor", GOSSIP_SENDER_MAIN, ID_GLYPHS+313); // 43359
                        break;
                    case CLASS_WARLOCK:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Curse of Exhaustion", GOSSIP_SENDER_MAIN, ID_GLYPHS+314); // 43392
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Souls", GOSSIP_SENDER_MAIN, ID_GLYPHS+315); // 43394
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Enslave Demon", GOSSIP_SENDER_MAIN, ID_GLYPHS+316); // 43393
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Kilrogg", GOSSIP_SENDER_MAIN, ID_GLYPHS+317); // 43391
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Drain Soul", GOSSIP_SENDER_MAIN, ID_GLYPHS+318); // 43390
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Unending Breath", GOSSIP_SENDER_MAIN, ID_GLYPHS+319); // 43389
                        break;
                    case CLASS_SHAMAN:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Thunderstorm", GOSSIP_SENDER_MAIN, ID_GLYPHS+320); // 44923
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Astral Recall", GOSSIP_SENDER_MAIN, ID_GLYPHS+321); // 43381
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Renewed Life", GOSSIP_SENDER_MAIN, ID_GLYPHS+322); // 43385
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Water Walking", GOSSIP_SENDER_MAIN, ID_GLYPHS+323); // 43388
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Water Breathing", GOSSIP_SENDER_MAIN, ID_GLYPHS+324); // 43344
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Water Shield", GOSSIP_SENDER_MAIN, ID_GLYPHS+325); // 43386
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Ghost Wolf", GOSSIP_SENDER_MAIN, ID_GLYPHS+326); // 43725
                        break;
                    case CLASS_DRUID:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Typhoon", GOSSIP_SENDER_MAIN, ID_GLYPHS+327); // 44922
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Challenging Roar", GOSSIP_SENDER_MAIN, ID_GLYPHS+328); // 43334
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Unburdened Rebirth", GOSSIP_SENDER_MAIN, ID_GLYPHS+329); // 43331
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Aquatic Form", GOSSIP_SENDER_MAIN, ID_GLYPHS+330); // 43316
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Dash", GOSSIP_SENDER_MAIN, ID_GLYPHS+331); // 43674
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Thorns", GOSSIP_SENDER_MAIN, ID_GLYPHS+332); // 43332
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of the Wild", GOSSIP_SENDER_MAIN, ID_GLYPHS+333); // 43335
                        break;
                    case CLASS_HUNTER:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of the Pack", GOSSIP_SENDER_MAIN, ID_GLYPHS+334); // 43355
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Feign Death", GOSSIP_SENDER_MAIN, ID_GLYPHS+335); // 43351
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Revive Pet", GOSSIP_SENDER_MAIN, ID_GLYPHS+336); // 43338
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Possessed Strength", GOSSIP_SENDER_MAIN, ID_GLYPHS+337); // 43354
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Scare Beast", GOSSIP_SENDER_MAIN, ID_GLYPHS+338); // 43356
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Mend Pet", GOSSIP_SENDER_MAIN, ID_GLYPHS+339); // 43350
                        break;
                    case CLASS_ROGUE:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Safe Fall", GOSSIP_SENDER_MAIN, ID_GLYPHS+340); // 43378
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Distract", GOSSIP_SENDER_MAIN, ID_GLYPHS+341); // 43376
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Vanish", GOSSIP_SENDER_MAIN, ID_GLYPHS+342); // 43380
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Pick Lock", GOSSIP_SENDER_MAIN, ID_GLYPHS+343); // 43377
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Blurred Speed", GOSSIP_SENDER_MAIN, ID_GLYPHS+344); // 43379
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Pick Pocket", GOSSIP_SENDER_MAIN, ID_GLYPHS+345); // 43343
                        break;
                    case CLASS_DEATH_KNIGHT:
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Blood Tap", GOSSIP_SENDER_MAIN, ID_GLYPHS+346); // 43535
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Death's Embrace", GOSSIP_SENDER_MAIN, ID_GLYPHS+347); // 43539
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Horn of Winter", GOSSIP_SENDER_MAIN, ID_GLYPHS+348); // 43544
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Corpse Explosion", GOSSIP_SENDER_MAIN, ID_GLYPHS+349); // 43671
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Pestilence", GOSSIP_SENDER_MAIN, ID_GLYPHS+350); // 43672
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Glyph of Raise Dead", GOSSIP_SENDER_MAIN, ID_GLYPHS+351); // 43673
                        break;
                    default:
                        break;
                }

                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, ID_GLYPHS);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Priest)
            if (action == ID_GLYPHS+6)
            {
                player->AddItem(42404, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Priest)
            if (action == ID_GLYPHS+7)
            {
                player->AddItem(42414, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Priest)
            if (action == ID_GLYPHS+8)
            {
                player->AddItem(42396, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Priest)
            if (action == ID_GLYPHS+9)
            {
                player->AddItem(42403, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Priest)
            if (action == ID_GLYPHS+10)
            {
                player->AddItem(45753, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Priest)
            if (action == ID_GLYPHS+11)
            {
                player->AddItem(45755, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Priest)
            if (action == ID_GLYPHS+12)
            {
                player->AddItem(45756, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Priest)
            if (action == ID_GLYPHS+13)
            {
                player->AddItem(45757, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Priest)
            if (action == ID_GLYPHS+14)
            {
                player->AddItem(45758, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Priest)
            if (action == ID_GLYPHS+15)
            {
                player->AddItem(45760, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Paladin)
            if (action == ID_GLYPHS+16)
            {
                player->AddItem(41107, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Paladin)
            if (action == ID_GLYPHS+17)
            {
                player->AddItem(41101, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Paladin)
            if (action == ID_GLYPHS+18)
            {
                player->AddItem(43867, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Paladin)
            if (action == ID_GLYPHS+19)
            {
                player->AddItem(43868, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Paladin)
            if (action == ID_GLYPHS+20)
            {
                player->AddItem(43869, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Paladin)
            if (action == ID_GLYPHS+21)
            {
                player->AddItem(41097, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Paladin)
            if (action == ID_GLYPHS+22)
            {
                player->AddItem(45741, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Paladin)
            if (action == ID_GLYPHS+23)
            {
                player->AddItem(45742, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Paladin)
            if (action == ID_GLYPHS+24)
            {
                player->AddItem(45743, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Paladin)
            if (action == ID_GLYPHS+15)
            {
                player->AddItem(45744, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }
            // Glyphs: Major (Warrior)
            if (action == ID_GLYPHS+26)
            {
                player->AddItem(43419, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Warrior)
            if (action == ID_GLYPHS+27)
            {
                player->AddItem(43415, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Warrior)
            if (action == ID_GLYPHS+28)
            {
                player->AddItem(45790, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Warrior)
            if (action == ID_GLYPHS+29)
            {
                player->AddItem(45792, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Warrior)
            if (action == ID_GLYPHS+30)
            {
                player->AddItem(45793, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Warrior)
            if (action == ID_GLYPHS+31)
            {
                player->AddItem(45794, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Warrior)
            if (action == ID_GLYPHS+32)
            {
                player->AddItem(45795, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Warrior)
            if (action == ID_GLYPHS+33)
            {
                player->AddItem(45797, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Warrior)
            if (action == ID_GLYPHS+34)
            {
                player->AddItem(43412, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Warrior)
            if (action == ID_GLYPHS+35)
            {
                player->AddItem(43421, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }
            // Glyphs: Major (Mage)
            if (action == ID_GLYPHS+36)
            {
                player->AddItem(44684, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Mage)
            if (action == ID_GLYPHS+37)
            {
                player->AddItem(42748, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Mage)
            if (action == ID_GLYPHS+38)
            {
                player->AddItem(42745, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Mage)
            if (action == ID_GLYPHS+39)
            {
                player->AddItem(42751, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Mage)
            if (action == ID_GLYPHS+40)
            {
                player->AddItem(44955, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Mage)
            if (action == ID_GLYPHS+41)
            {
                player->AddItem(42754, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Mage)
            if (action == ID_GLYPHS+42)
            {
                player->AddItem(50045, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Mage)
            if (action == ID_GLYPHS+43)
            {
                player->AddItem(42736, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Mage)
            if (action == ID_GLYPHS+44)
            {
                player->AddItem(45736, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Mage)
            if (action == ID_GLYPHS+45)
            {
                player->AddItem(45737, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }
            // Glyphs: Major (Warlock)
            if (action == ID_GLYPHS+46)
            {
                player->AddItem(42459, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Warlock)
            if (action == ID_GLYPHS+47)
            {
                player->AddItem(42472, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Warlock)
            if (action == ID_GLYPHS+48)
            {
                player->AddItem(42457, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Warlock)
            if (action == ID_GLYPHS+49)
            {
                player->AddItem(42454, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Warlock)
            if (action == ID_GLYPHS+50)
            {
                player->AddItem(42463, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Warlock)
            if (action == ID_GLYPHS+51)
            {
                player->AddItem(45779, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Warlock)
            if (action == ID_GLYPHS+52)
            {
                player->AddItem(45780, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Warlock)
            if (action == ID_GLYPHS+53)
            {
                player->AddItem(45781, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Warlock)
            if (action == ID_GLYPHS+54)
            {
                player->AddItem(45782, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Warlock)
            if (action == ID_GLYPHS+55)
            {
                player->AddItem(45783, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }
            // Glyphs: Major (Shaman)
            if (action == ID_GLYPHS+56)
            {
                player->AddItem(41529, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Shaman)
            if (action == ID_GLYPHS+57)
            {
                player->AddItem(41524, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Shaman)
            if (action == ID_GLYPHS+58)
            {
                player->AddItem(41552, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Shaman)
            if (action == ID_GLYPHS+59)
            {
                player->AddItem(41517, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Shaman)
            if (action == ID_GLYPHS+60)
            {
                player->AddItem(41538, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Shaman)
            if (action == ID_GLYPHS+61)
            {
                player->AddItem(41539, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Shaman)
            if (action == ID_GLYPHS+62)
            {
                player->AddItem(45770, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Shaman)
            if (action == ID_GLYPHS+63)
            {
                player->AddItem(45771, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Shaman)
            if (action == ID_GLYPHS+64)
            {
                player->AddItem(45772, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Shaman)
            if (action == ID_GLYPHS+65)
            {
                player->AddItem(45775, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }
            // Glyphs: Major (Druid)
            if (action == ID_GLYPHS+66)
            {
                player->AddItem(40915, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Druid)
            if (action == ID_GLYPHS+67)
            {
                player->AddItem(44928, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Druid)
            if (action == ID_GLYPHS+68)
            {
                player->AddItem(40921, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Druid)
            if (action == ID_GLYPHS+69)
            {
                player->AddItem(40900, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Druid)
            if (action == ID_GLYPHS+70)
            {
                player->AddItem(40906, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Druid)
            if (action == ID_GLYPHS+71)
            {
                player->AddItem(40908, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Druid)
            if (action == ID_GLYPHS+72)
            {
                player->AddItem(40920, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Druid)
            if (action == ID_GLYPHS+73)
            {
                player->AddItem(45601, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Druid)
            if (action == ID_GLYPHS+74)
            {
                player->AddItem(45602, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Druid)
            if (action == ID_GLYPHS+75)
            {
                player->AddItem(45603, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }
            // Glyphs: Major (Hunter)
            if (action == ID_GLYPHS+76)
            {
                player->AddItem(42913, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Hunter)
            if (action == ID_GLYPHS+77)
            {
                player->AddItem(42914, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Hunter)
            if (action == ID_GLYPHS+78)
            {
                player->AddItem(42902, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Hunter)
            if (action == ID_GLYPHS+79)
            {
                player->AddItem(42915, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Hunter)
            if (action == ID_GLYPHS+80)
            {
                player->AddItem(42916, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Hunter)
            if (action == ID_GLYPHS+81)
            {
                player->AddItem(42917, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Hunter)
            if (action == ID_GLYPHS+82)
            {
                player->AddItem(45625, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Hunter)
            if (action == ID_GLYPHS+83)
            {
                player->AddItem(45731, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Hunter)
            if (action == ID_GLYPHS+84)
            {
                player->AddItem(45732, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Hunter)
            if (action == ID_GLYPHS+85)
            {
                player->AddItem(45733, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }
            // Glyphs: Major (Rogue)
            if (action == ID_GLYPHS+86)
            {
                player->AddItem(42971, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Rogue)
            if (action == ID_GLYPHS+87)
            {
                player->AddItem(42959, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Rogue)
            if (action == ID_GLYPHS+88)
            {
                player->AddItem(42954, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Rogue)
            if (action == ID_GLYPHS+89)
            {
                player->AddItem(45761, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Rogue)
            if (action == ID_GLYPHS+90)
            {
                player->AddItem(45762, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Rogue)
            if (action == ID_GLYPHS+91)
            {
                player->AddItem(45764, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Rogue)
            if (action == ID_GLYPHS+92)
            {
                player->AddItem(45766, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Rogue)
            if (action == ID_GLYPHS+93)
            {
                player->AddItem(45767, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Rogue)
            if (action == ID_GLYPHS+94)
            {
                player->AddItem(45768, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Rogue)
            if (action == ID_GLYPHS+95)
            {
                player->AddItem(45769, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }
            // Glyphs: Major (Death Knight)
            if (action == ID_GLYPHS+96)
            {
                player->AddItem(43533, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Death Knight)
            if (action == ID_GLYPHS+97)
            {
                player->AddItem(43534, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Death Knight)
            if (action == ID_GLYPHS+98)
            {
                player->AddItem(43536, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Death Knight)
            if (action == ID_GLYPHS+99)
            {
                player->AddItem(43537, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Death Knight)
            if (action == ID_GLYPHS+100)
            {
                player->AddItem(43538, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Death Knight)
            if (action == ID_GLYPHS+101)
            {
                player->AddItem(43541, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Death Knight)
            if (action == ID_GLYPHS+102)
            {
                player->AddItem(43542, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Death Knight)
            if (action == ID_GLYPHS+103)
            {
                player->AddItem(43543, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Death Knight)
            if (action == ID_GLYPHS+104)
            {
                player->AddItem(43545, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Major (Death Knight)
            if (action == ID_GLYPHS+105)
            {
                player->AddItem(43546, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Priest)
            if (action == ID_GLYPHS+287)
            {
                player->AddItem(43374, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Priest)
            if (action == ID_GLYPHS+288)
            {
                player->AddItem(43370, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Priest)
            if (action == ID_GLYPHS+289)
            {
                player->AddItem(43372, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Priest)
            if (action == ID_GLYPHS+290)
            {
                player->AddItem(43373, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Priest)
            if (action == ID_GLYPHS+291)
            {
                player->AddItem(43342, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Priest)
            if (action == ID_GLYPHS+292)
            {
                player->AddItem(43371, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Paladin)
            if (action == ID_GLYPHS+293)
            {
                player->AddItem(43369, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Paladin)
            if (action == ID_GLYPHS+294)
            {
                player->AddItem(43365, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Paladin)
            if (action == ID_GLYPHS+295)
            {
                player->AddItem(43368, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Paladin)
            if (action == ID_GLYPHS+296)
            {
                player->AddItem(43366, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Paladin)
            if (action == ID_GLYPHS+297)
            {
                player->AddItem(43367, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Paladin)
            if (action == ID_GLYPHS+298)
            {
                player->AddItem(43340, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Warrior)
            if (action == ID_GLYPHS+299)
            {
                player->AddItem(49084, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Warrior)
            if (action == ID_GLYPHS+300)
            {
                player->AddItem(43400, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Warrior)
            if (action == ID_GLYPHS+301)
            {
                player->AddItem(43398, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Warrior)
            if (action == ID_GLYPHS+302)
            {
                player->AddItem(43396, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Warrior)
            if (action == ID_GLYPHS+303)
            {
                player->AddItem(43399, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Warrior)
            if (action == ID_GLYPHS+304)
            {
                player->AddItem(43397, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Warrior)
            if (action == ID_GLYPHS+305)
            {
                player->AddItem(43395, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Mage)
            if (action == ID_GLYPHS+306)
            {
                player->AddItem(44920, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Mage)
            if (action == ID_GLYPHS+307)
            {
                player->AddItem(43360, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Mage)
            if (action == ID_GLYPHS+308)
            {
                player->AddItem(43357, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Mage)
            if (action == ID_GLYPHS+309)
            {
                player->AddItem(43364, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Mage)
            if (action == ID_GLYPHS+310)
            {
                player->AddItem(43361, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Mage)
            if (action == ID_GLYPHS+311)
            {
                player->AddItem(43362, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Mage)
            if (action == ID_GLYPHS+312)
            {
                player->AddItem(43339, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Mage)
            if (action == ID_GLYPHS+313)
            {
                player->AddItem(43359, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Warlock)
            if (action == ID_GLYPHS+314)
            {
                player->AddItem(43392, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Warlock)
            if (action == ID_GLYPHS+315)
            {
                player->AddItem(43394, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Warlock)
            if (action == ID_GLYPHS+316)
            {
                player->AddItem(43393, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Warlock)
            if (action == ID_GLYPHS+317)
            {
                player->AddItem(43391, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Warlock)
            if (action == ID_GLYPHS+318)
            {
                player->AddItem(43390, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Warlock)
            if (action == ID_GLYPHS+319)
            {
                player->AddItem(43389, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Shaman)
            if (action == ID_GLYPHS+320)
            {
                player->AddItem(44923, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Shaman)
            if (action == ID_GLYPHS+321)
            {
                player->AddItem(43381, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Shaman)
            if (action == ID_GLYPHS+322)
            {
                player->AddItem(43385, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Shaman)
            if (action == ID_GLYPHS+323)
            {
                player->AddItem(43388, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Shaman)
            if (action == ID_GLYPHS+324)
            {
                player->AddItem(43344, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Shaman)
            if (action == ID_GLYPHS+325)
            {
                player->AddItem(43386, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Shaman)
            if (action == ID_GLYPHS+326)
            {
                player->AddItem(43725, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Druid)
            if (action == ID_GLYPHS+327)
            {
                player->AddItem(44922, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Druid)
            if (action == ID_GLYPHS+328)
            {
                player->AddItem(43334, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Druid)
            if (action == ID_GLYPHS+329)
            {
                player->AddItem(43331, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Druid)
            if (action == ID_GLYPHS+330)
            {
                player->AddItem(43316, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Druid)
            if (action == ID_GLYPHS+331)
            {
                player->AddItem(43674, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Druid)
            if (action == ID_GLYPHS+332)
            {
                player->AddItem(43332, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Druid)
            if (action == ID_GLYPHS+333)
            {
                player->AddItem(43335, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Hunter)
            if (action == ID_GLYPHS+334)
            {
                player->AddItem(43355, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Hunter)
            if (action == ID_GLYPHS+335)
            {
                player->AddItem(43351, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Hunter)
            if (action == ID_GLYPHS+336)
            {
                player->AddItem(43338, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Hunter)
            if (action == ID_GLYPHS+337)
            {
                player->AddItem(43354, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Hunter)
            if (action == ID_GLYPHS+338)
            {
                player->AddItem(43356, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Hunter)
            if (action == ID_GLYPHS+339)
            {
                player->AddItem(43350, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Rogue)
            if (action == ID_GLYPHS+340)
            {
                player->AddItem(43378, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Rogue)
            if (action == ID_GLYPHS+341)
            {
                player->AddItem(43376, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Rogue)
            if (action == ID_GLYPHS+342)
            {
                player->AddItem(43380, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Rogue)
            if (action == ID_GLYPHS+343)
            {
                player->AddItem(43377, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Rogue)
            if (action == ID_GLYPHS+344)
            {
                player->AddItem(43379, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Rogue)
            if (action == ID_GLYPHS+345)
            {
                player->AddItem(43343, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Death Knight)
            if (action == ID_GLYPHS+346)
            {
                player->AddItem(43535, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Death Knight)
            if (action == ID_GLYPHS+347)
            {
                player->AddItem(43539, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Death Knight)
            if (action == ID_GLYPHS+348)
            {
                player->AddItem(43544, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Death Knight)
            if (action == ID_GLYPHS+349)
            {
                player->AddItem(43671, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Death Knight)
            if (action == ID_GLYPHS+350)
            {
                player->AddItem(43672, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor (Death Knight)
            if (action == ID_GLYPHS+351)
            {
                player->AddItem(43673, 1);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
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

                OnGossipHello(player, creature);
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

                OnGossipHello(player, creature);
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

                OnGossipHello(player, creature);
            }

            return true;
        }
};

void AddKickstarterScripts()
{
    new Kickstarter();
}
