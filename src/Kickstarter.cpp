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
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "", GOSSIP_SENDER_MAIN, ID_GEMS+100); // 40142
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "", GOSSIP_SENDER_MAIN, ID_GEMS+101); // 40143
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "", GOSSIP_SENDER_MAIN, ID_GEMS+102); // 40144
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "", GOSSIP_SENDER_MAIN, ID_GEMS+103); // 40145
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "", GOSSIP_SENDER_MAIN, ID_GEMS+104); // 40146
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "", GOSSIP_SENDER_MAIN, ID_GEMS+105); // 40147
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "", GOSSIP_SENDER_MAIN, ID_GEMS+106); // 40148
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "", GOSSIP_SENDER_MAIN, ID_GEMS+107); // 40149
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "", GOSSIP_SENDER_MAIN, ID_GEMS+108); // 40150
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "", GOSSIP_SENDER_MAIN, ID_GEMS+109); // 40151
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Next Page", GOSSIP_SENDER_MAIN, ID_GEMS+98);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, ID_GEMS);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Orange
            if (action == ID_GEMS+98)
            {
                ClearGossipMenuFor(player);
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "", GOSSIP_SENDER_MAIN, ID_GEMS+110); // 40152
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "", GOSSIP_SENDER_MAIN, ID_GEMS+111); // 40153
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "", GOSSIP_SENDER_MAIN, ID_GEMS+112); // 40154
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "", GOSSIP_SENDER_MAIN, ID_GEMS+113); // 40155
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "", GOSSIP_SENDER_MAIN, ID_GEMS+114); // 40156
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "", GOSSIP_SENDER_MAIN, ID_GEMS+115); // 40157
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "", GOSSIP_SENDER_MAIN, ID_GEMS+116); // 40158
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "", GOSSIP_SENDER_MAIN, ID_GEMS+117); // 40159
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "", GOSSIP_SENDER_MAIN, ID_GEMS+118); // 40160
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "", GOSSIP_SENDER_MAIN, ID_GEMS+119); // 40161
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Next Page", GOSSIP_SENDER_MAIN, ID_GEMS+99);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, ID_GEMS+97);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Gems: Orange
            if (action == ID_GEMS+99)
            {
                ClearGossipMenuFor(player);
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "", GOSSIP_SENDER_MAIN, ID_GEMS+120); // 40162
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "", GOSSIP_SENDER_MAIN, ID_GEMS+121); // 40163
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, ID_GEMS+98);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs
            if (action == ID_GLYPHS)
            {
                ClearGossipMenuFor(player);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "Major", GOSSIP_SENDER_MAIN, ID_GLYPHS+1);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "Minor", GOSSIP_SENDER_MAIN, ID_GLYPHS+2);
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
                        break;
                    case CLASS_PALADIN:
                        break;
                    case CLASS_WARRIOR:
                        break;
                    case CLASS_MAGE:
                        break;
                    case CLASS_WARLOCK:
                        break;
                    case CLASS_SHAMAN:
                        break;
                    case CLASS_DRUID:
                        break;
                    case CLASS_HUNTER:
                        break;
                    case CLASS_ROGUE:
                        break;
                    case CLASS_DEATH_KNIGHT:
                        break;
                    default:
                        break;
                }

                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, ID_GLYPHS);
                SendGossipMenuFor(player, TEXT_KICKSTARTER_NEED, creature->GetGUID());
            }

            // Glyphs: Minor
            if (action == ID_GLYPHS+2)
            {
                ClearGossipMenuFor(player);

                switch (player->getClass())
                {
                    case CLASS_PRIEST:
                        break;
                    case CLASS_PALADIN:
                        break;
                    case CLASS_WARRIOR:
                        break;
                    case CLASS_MAGE:
                        break;
                    case CLASS_WARLOCK:
                        break;
                    case CLASS_SHAMAN:
                        break;
                    case CLASS_DRUID:
                        break;
                    case CLASS_HUNTER:
                        break;
                    case CLASS_ROGUE:
                        break;
                    case CLASS_DEATH_KNIGHT:
                        break;
                    default:
                        break;
                }

                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, ID_GLYPHS);
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
