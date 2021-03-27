#include "Player.h"
#include "ScriptedGossip.h"
#include "Chat.h"
#include "ScriptMgr.h"
#include "Config.h"

#define TEXT_KICKSTARTER 9000000

#define ID_EQUIPMENT 100
#define ID_GEMS 200
#define ID_GLYPHS 300
#define ID_SPELLS 400
#define ID_PROFICIENCY 500
#define ID_MOUNTS 600

#define VENDOR_EQUIPMENT 9000000
#define VENDOR_ACCESSORIES 9000004
#define VENDOR_WEAPONS 9000008
#define VENDOR_GEMS 9000025
#define VENDOR_GLYPHS 9000032

#define PROFICIENCY_BLOCK 107
#define PROFICIENCY_ONE_HANDED_AXES 196
#define PROFICIENCY_TWO_HANDED_AXES 197
#define PROFICIENCY_ONE_HANDED_MACES 198
#define PROFICIENCY_TWO_HANDED_MACES 199
#define PROFICIENCY_POLEARMS 200
#define PROFICIENCY_ONE_HANDED_SWORDS 201
#define PROFICIENCY_TWO_HANDED_SWORDS 202
#define PROFICIENCY_STAVES 227
#define PROFICIENCY_BOWS 264
#define PROFICIENCY_GUNS 266
#define PROFICIENCY_DUAL_WIELD 674
#define PROFICIENCY_PLATE_MAIL 750
#define PROFICIENCY_DAGGERS 1180
#define PROFICIENCY_THROWN 2567
#define PROFICIENCY_PARRY 3127
#define PROFICIENCY_WANDS 5009
#define PROFICIENCY_CROSSBOWS 5011
#define PROFICIENCY_MAIL 8737
#define PROFICIENCY_SHIELD 9116
#define PROFICIENCY_FIST_WEAPONS 15590

int spellPaladin[]     = { 53408, 642, 498, 1022, 5599, 10278, 62124, 1044, 6940, 1038, 853, 5588, 5589, 10308, 7294, 10298, 10299, 10300, 10301, 27150, 54043, 19876, 19895, 19896, 27151, 48943, 19742, 19850, 19852, 19853, 19854, 25290, 27142, 48935, 48936, 25894, 25918, 27143, 48937, 48938, 19888, 19897, 19898, 27152, 48945, 31884, 19891, 19899, 19900, 27153, 48947, 2812, 10318, 27139, 48816, 48817, 54428, 633, 2800, 10310, 27154, 48788, 19740, 19834, 19835, 19836, 19837, 19838, 25291, 27140, 48931, 48932, 25782, 25916, 27141, 48933, 48934, 20217, 25898, 465, 10290, 643, 10291, 1032, 10292, 10293, 27149, 48941, 48942, 19752, 879, 5614, 5615, 10312, 10313, 10314, 27138, 48800, 48801, 1152, 19750, 19939, 19940, 19941, 19942, 19943, 27137, 48784, 48785, 32223, 24275, 24274, 24239, 27180, 48805, 48806, 53407, 20271, 20186, 7328, 10322, 10324, 20772, 20773, 48949, 48950, 53601, 20165, 21084, 20166, 20164, 53600, 61411, 31789, 25780, 5502, 10326, 635, 639, 647, 1026, 1042, 3472, 10328, 10329, 25292, 27135, 27136, 48781, 48782, 4987, 19746, 26573, 20116, 20922, 20923, 20924, 27173, 48818, 48819 };
int spellWarrior[]     = { 2457, 100, 6178, 11578, 1715, 78, 284, 285, 1608, 11564, 11565, 11566, 11567, 25286, 29707, 30324, 47449, 47450, 57755, 694, 7384, 772, 6546, 6547, 6548, 11572, 11573, 11574, 25208, 46845, 47465, 20230, 64382, 6343, 8198, 8204, 8205, 11580, 11581, 25264, 47501, 47502, 6673, 5242, 6192, 11549, 11550, 11551, 25289, 2048, 47436, 18499, 2458, 1161, 845, 7369, 11608, 11609, 20569, 25231, 47519, 47520, 469, 47439, 47440, 1160, 6190, 11554, 11555, 11556, 25202, 25203, 47437, 55694, 5308, 20658, 20660, 20661, 20662, 25234, 25236, 47470, 47471, 20252, 5246, 6552, 1719, 1464, 8820, 11604, 11605, 25241, 25242, 47474, 47475, 34428, 1680, 2687, 71, 676, 3411, 6572, 6574, 7379, 11600, 11601, 25288, 25269, 30357, 57823, 72, 2565, 23922, 23923, 23924, 23925, 25258, 30356, 47487, 47488, 871, 23920, 7386, 12678, 355 };
int spellMage[]        = { 1008, 8455, 10169, 10170, 27130, 33946, 43017, 30451, 42894, 42896, 42897, 23028, 27127, 43002, 1449, 8437, 8438, 8439, 10201, 10202, 27080, 27082, 42920, 42921, 1459, 1460, 1461, 10156, 10157, 27126, 42995, 5143, 5144, 5145, 8416, 8417, 10211, 10212, 25345, 27075, 38699, 38704, 42843, 42846, 1953, 587, 597, 990, 6129, 10144, 10145, 28612, 33717, 759, 3552, 10053, 10054, 27101, 42985, 42955, 42956, 5504, 5505, 5506, 6127, 10138, 10139, 10140, 37420, 27090, 2139, 604, 8450, 8451, 10173, 10174, 33944, 43015, 12051, 66, 6117, 22782, 22783, 27125, 43023, 43024, 1463, 8494, 8495, 10191, 10192, 10193, 27131, 43019, 43020, 55342, 118, 12824, 12825, 12826, 475, 43987, 58659, 130, 30449, 2136, 2137, 2138, 8412, 8413, 10197, 10199, 27078, 27079, 42872, 42873, 543, 8457, 8458, 10223, 10225, 27128, 43010, 133, 143, 145, 3140, 8400, 8401, 8402, 10148, 10149, 10150, 10151, 25306, 27070, 38692, 42832, 42833, 2120, 2121, 8422, 8423, 10215, 10216, 27086, 42925, 42926, 44614, 47610, 30482, 43045, 43046, 2948, 8444, 8445, 8446, 10205, 10206, 10207, 27073, 27074, 42858, 42859, 10, 6141, 8427, 10185, 10186, 10187, 27085, 42939, 42940, 120, 8492, 10159, 10160, 10161, 27087, 42930, 42931, 168, 7300, 7301, 122, 865, 6131, 10230, 27088, 42917, 6143, 8461, 8462, 10177, 28609, 32796, 43012, 116, 205, 837, 7322, 8406, 8407, 8408, 10179, 10180, 10181, 25304, 27071, 27072, 38697, 42841, 42842, 7302, 7320, 10219, 10220, 27124, 43008, 45438, 30455, 42913, 42914 };
int spellWarlock[]     = { 686, 687, 126, 132, 172, 348, 603, 688, 689, 691, 693, 695, 696, 697, 698, 699, 702, 705, 706, 707, 709, 710, 712, 755, 980, 1014, 1086, 1088, 1094, 1098, 1106, 1108, 1120, 1454, 1455, 1456, 1490, 1714, 1949, 2362, 2941, 3698, 3699, 3700, 5138, 5484, 5500, 5676, 5697, 5699, 5740, 5782, 6201, 6202, 6205, 6213, 6215, 6217, 6219, 6222, 6223, 6229, 6353, 6366, 6789, 7641, 7646, 7648, 7651, 8288, 8289, 11659, 11660, 11661, 11665, 11667, 11668, 11671, 11672, 11675, 11677, 11678, 11683, 11684, 11687, 11688, 11689, 11693, 11694, 11695, 11699, 11700, 11707, 11708, 11711, 11712, 11713, 11719, 11721, 11722, 11725, 11726, 11729, 11730, 11733, 11734, 11735, 11739, 11740, 17727, 17728, 17919, 17920, 17921, 17922, 17923, 17924, 17925, 17926, 17928, 17951, 17952, 17953, 18647, 20752, 20755, 20756, 20757, 25307, 25309, 25311, 27209, 27210, 27211, 27212, 27213, 27215, 27216, 27217, 27218, 27219, 27220, 27222, 27223, 27224, 27228, 27230, 27238, 27243, 27250, 27259, 27260, 28172, 28176, 28189, 28610, 29722, 29858, 29893, 30459, 30545, 30909, 30910, 32231, 47793, 47808, 47809, 47810, 47811, 47812, 47813, 47814, 47815, 47819, 47820, 47823, 47824, 47825, 47835, 47836, 47837, 47838, 47855, 47856, 47857, 47859, 47860, 47863, 47864, 47865, 47867, 47871, 47878, 47884, 47886, 47888, 47889, 47890, 47891, 47892, 47893, 47897, 48018, 48020, 50511, 57946, 58887, 60219, 60220, 61191, 61290 };
int spellShaman[]      = { 403, 331, 131, 324, 325, 332, 370, 421, 526, 529, 546, 547, 548, 556, 905, 913, 915, 930, 939, 943, 945, 959, 1064, 1535, 2008, 2062, 2484, 2645, 2825, 2860, 2894, 3599, 3738, 5394, 5675, 5730, 6041, 6196, 6363, 6364, 6365, 6375, 6377, 6390, 6391, 6392, 6495, 8004, 8005, 8008, 8010, 8012, 8017, 8018, 8019, 8024, 8027, 8030, 8033, 8038, 8042, 8044, 8045, 8046, 8050, 8052, 8053, 8056, 8058, 8071, 8075, 8134, 8143, 8154, 8155, 8160, 8161, 8170, 8177, 8181, 8184, 8190, 8227, 8232, 8235, 8249, 8498, 8499, 8512, 10391, 10392, 10395, 10396, 10399, 10406, 10407, 10408, 10412, 10413, 10414, 10427, 10428, 10431, 10432, 10437, 10438, 10442, 10447, 10448, 10456, 10462, 10463, 10466, 10467, 10468, 10472, 10473, 10478, 10479, 10486, 10495, 10496, 10497, 10526, 10537, 10538, 10585, 10586, 10587, 10595, 10600, 10601, 10605, 10622, 10623, 11314, 11315, 15207, 15208, 16339, 16341, 16342, 16355, 16356, 16362, 16387, 20608, 20609, 20610, 20776, 20777, 24398, 25357, 25361, 25391, 25396, 25420, 25422, 25423, 25439, 25442, 25448, 25449, 25454, 25457, 25464, 25469, 25472, 25489, 25500, 25505, 25508, 25509, 25525, 25528, 25533, 25546, 25547, 25552, 25557, 25560, 25563, 25567, 25570, 25574, 25590, 29228, 33736, 36936, 49230, 49231, 49232, 49233, 49235, 49236, 49237, 49238, 49270, 49271, 49272, 49273, 49275, 49276, 49277, 49280, 49281, 51505, 51514, 51730, 51988, 51991, 51992, 51993, 51994, 52127, 52129, 52131, 52134, 52136, 52138, 55458, 55459, 57622, 57960, 57994, 58580, 58581, 58582, 58643, 58649, 58652, 58656, 58699, 58703, 58704, 58731, 58734, 58737, 58739, 58741, 58745, 58746, 58749, 58751, 58753, 58755, 58756, 58757, 58771, 58773, 58774, 58785, 58789, 58790, 58794, 58795, 58796, 58801, 58803, 58804, 60043, 61649, 61657, 66842, 66843, 66844 };
int spellDruid[]       = { 5176, 5185, 99, 339, 467, 740, 768, 769, 770, 774, 779, 780, 782, 783, 1058, 1062, 1066, 1075, 1079, 1082, 1126, 1430, 1735, 1822, 1823, 1824, 1850, 2090, 2091, 2637, 2782, 2893, 2908, 2912, 3029, 3627, 5177, 5178, 5179, 5180, 5186, 5187, 5188, 5189, 5195, 5196, 5201, 5209, 5211, 5215, 5217, 5221, 5225, 5229, 5232, 5234, 5487, 6756, 6778, 6780, 6785, 6787, 6793, 6795, 6798, 6800, 6807, 6808, 6809, 8903, 8905, 8907, 8910, 8914, 8918, 8921, 8924, 8925, 8926, 8927, 8928, 8929, 8936, 8938, 8939, 8940, 8941, 8949, 8950, 8951, 8955, 8972, 8983, 8992, 8998, 9000, 9005, 9490, 9492, 9493, 9634, 9745, 9747, 9750, 9752, 9754, 9756, 9758, 9821, 9823, 9827, 9829, 9830, 9833, 9834, 9835, 9839, 9840, 9841, 9845, 9846, 9849, 9850, 9852, 9853, 9856, 9857, 9858, 9862, 9863, 9866, 9867, 9875, 9876, 9880, 9881, 9884, 9885, 9888, 9889, 9892, 9894, 9896, 9898, 9901, 9904, 9908, 9910, 9912, 16689, 16810, 16811, 16812, 16813, 16857, 16914, 17329, 17401, 17402, 18657, 18658, 20484, 20719, 20739, 20742, 20747, 20748, 21849, 21850, 22568, 22570, 22812, 22827, 22828, 22829, 22842, 24248, 25297, 25298, 25299, 26978, 26979, 26980, 26981, 26982, 26983, 26984, 26985, 26986, 26987, 26988, 26989, 26990, 26991, 26992, 26994, 26995, 26996, 26997, 26998, 27000, 27001, 27002, 27003, 27004, 27005, 27006, 27008, 27009, 27012, 29166, 31018, 31709, 33357, 33745, 33763, 33786, 48377, 48378, 48440, 48441, 48442, 48443, 48446, 48447, 48450, 48451, 48459, 48461, 48462, 48463, 48464, 48465, 48467, 48469, 48470, 48477, 48479, 48480, 48559, 48560, 48561, 48562, 48567, 48568, 48569, 48570, 48571, 48572, 48573, 48574, 48575, 48576, 48577, 48578, 48579, 49799, 49800, 49802, 49803, 50212, 50213, 50464, 50763, 50764, 50765, 50766, 50767, 50768, 50769, 52610, 53307, 53308, 53312, 62078, 62600 };
int spellHunter[]      = { 2973, 136, 781, 883, 982, 1002, 1130, 1462, 1494, 1495, 1499, 1510, 1513, 1515, 1543, 1978, 2641, 2643, 2974, 3034, 3043, 3044, 3045, 3111, 3661, 3662, 5116, 5118, 5384, 6197, 6991, 13159, 13161, 13163, 13165, 13542, 13543, 13544, 13549, 13550, 13551, 13552, 13553, 13554, 13555, 13795, 13809, 13813, 14260, 14261, 14262, 14263, 14264, 14265, 14266, 14269, 14270, 14271, 14281, 14282, 14283, 14284, 14285, 14286, 14287, 14288, 14289, 14290, 14294, 14295, 14302, 14303, 14304, 14305, 14310, 14311, 14316, 14317, 14318, 14319, 14320, 14321, 14322, 14323, 14324, 14325, 14326, 14327, 19263, 19801, 19878, 19879, 19880, 19882, 19883, 19884, 19885, 20043, 20190, 20736, 25294, 25295, 25296, 27014, 27016, 27019, 27021, 27022, 27023, 27025, 27044, 27045, 27046, 34026, 34074, 34120, 34477, 34600, 36916, 48989, 48990, 48995, 48996, 49000, 49001, 49044, 49045, 49047, 49048, 49051, 49052, 49055, 49056, 49066, 49067, 49071, 53271, 53338, 53339, 53351, 56641, 58431, 58434, 60192, 61005, 61006, 61846, 61847, 62757 };
int spellRogue[]       = { 2098, 1752, 53, 408, 703, 921, 1725, 1757, 1758, 1759, 1760, 1766, 1776, 1784, 1804, 1833, 1842, 1856, 1857, 1860, 1943, 1966, 2070, 2094, 2589, 2590, 2591, 2836, 2983, 3127, 5171, 5277, 5938, 6760, 6761, 6762, 6768, 6770, 6774, 8621, 8623, 8624, 8631, 8632, 8633, 8637, 8639, 8640, 8643, 8647, 8676, 8696, 8721, 8724, 8725, 11267, 11268, 11269, 11273, 11274, 11275, 11279, 11280, 11281, 11289, 11290, 11293, 11294, 11297, 11299, 11300, 11303, 11305, 25300, 25302, 26669, 26679, 26839, 26861, 26862, 26863, 26865, 26867, 26884, 26889, 27441, 27448, 31016, 31224, 32645, 32684, 48637, 48638, 48656, 48657, 48658, 48659, 48667, 48668, 48671, 48672, 48673, 48674, 48675, 48676, 48689, 48690, 48691, 51722, 51723, 51724, 57934, 57992, 57993 };
int spellDeathKnight[] = { 48266, 45902, 45477, 47541, 50977, 49576, 45462, 3714, 42650, 43265, 45463, 45524, 45529, 46584, 47476, 47528, 47568, 48263, 48265, 48707, 48721, 48743, 48792, 49020, 49892, 49893, 49894, 49895, 49896, 49903, 49904, 49909, 49917, 49918, 49919, 49920, 49921, 49923, 49924, 49926, 49927, 49928, 49929, 49930, 49936, 49937, 49938, 49939, 49940, 49941, 49998, 49999, 50842, 51423, 51424, 51425, 53323, 53331, 53342, 53344, 54446, 54447, 56222, 56815, 57330, 57623, 61999, 62158, 70164 };

int spellPriest[208][2] = { {1243, 1}, {2050, 1}, {585, 1}, {2052, 4}, {589, 4}, {591, 6}, {17, 6}, {586, 8}, {139, 8}, {2006, 10}, {2053, 10}, {8092, 10}, {594, 10}, {592, 12}, {588, 12}, {1244, 12}, {598, 14}, {6074, 14}, {8122, 14}, {528, 14}, {2054, 16}, {8102, 16}, {600, 18}, {527, 18}, {970, 18}, {7128, 20}, {9484, 20}, {14914, 20}, {2061, 20}, {15237, 20}, {6075, 20}, {2944, 20}, {453, 20}, {6346, 20}, {2055, 22}, {2010, 22}, {984, 22}, {2096, 22}, {8103, 22}, {1245, 24}, {3747, 24}, {15262, 24}, {8129, 24}, {9472, 26}, {6076, 26}, {992, 26}, {6063, 28}, {15430, 28}, {8124, 28}, {19276, 28}, {8104, 28}, {6065, 30}, {602, 30}, {14752, 30}, {596, 30}, {15263, 30}, {1004, 30}, {976, 30}, {605, 30}, {552, 32}, {9473, 32}, {6077, 32}, {6064, 34}, {10880, 34}, {8105, 34}, {2767, 34}, {1706, 34}, {6066, 36}, {988, 36}, {2791, 36}, {15264, 36}, {15431, 36}, {19277, 36}, {9474, 38}, {6060, 38}, {6078, 38}, {1006, 40}, {14818, 40}, {9485, 40}, {996, 40}, {2060, 40}, {8106, 40}, {10898, 42}, {15265, 42}, {10888, 42}, {10957, 42}, {10892, 42}, {10915, 44}, {27799, 44}, {10927, 44}, {10909, 44}, {19278, 44}, {10963, 46}, {10881, 46}, {10933, 46}, {10945, 46}, {10899, 48}, {10937, 48}, {21562, 48}, {15266, 48}, {10951, 50}, {14819, 50}, {10960, 50}, {10916, 50}, {10928, 50}, {10893, 50}, {10964, 52}, {27800, 52}, {19279, 52}, {10946, 52}, {10900, 54}, {15267, 54}, {10934, 54}, {10917, 56}, {10929, 56}, {10890, 56}, {10958, 56}, {27683, 56}, {10965, 58}, {20770, 58}, {10947, 58}, {10894, 58}, {10952, 60}, {27841, 60}, {10901, 60}, {10938, 60}, {21564, 60}, {27681, 60}, {10955, 60}, {10961, 60}, {25316, 60}, {25314, 60}, {15261, 60}, {27801, 60}, {25315, 60}, {19280, 60}, {25233, 61}, {25363, 61}, {32379, 62}, {25210, 63}, {25372, 63}, {32546, 64}, {25217, 65}, {25221, 65}, {25367, 65}, {25384, 66}, {34433, 66}, {25235, 67}, {25308, 68}, {25213, 68}, {25435, 68}, {33076, 68}, {25331, 68}, {25433, 68}, {25467, 68}, {25431, 69}, {25364, 69}, {25375, 69}, {25312, 70}, {25218, 70}, {25389, 70}, {25392, 70}, {32999, 70}, {25222, 70}, {39374, 70}, {32996, 70}, {32375, 70}, {25368, 70}, {48040, 71}, {48119, 72}, {48134, 72}, {48062, 73}, {48070, 73}, {48299, 73}, {48112, 74}, {48122, 74}, {48126, 74}, {48065, 75}, {48077, 75}, {48067, 75}, {48045, 75}, {48157, 75}, {48124, 75}, {48072, 76}, {48169, 76}, {48168, 77}, {48170, 77}, {48120, 78}, {48063, 78}, {48135, 78}, {48171, 78}, {48071, 79}, {48113, 79}, {48123, 79}, {48300, 79}, {48127, 79}, {48073, 80}, {48161, 80}, {48066, 80}, {48162, 80}, {48074, 80}, {48078, 80}, {48068, 80}, {53023, 80}, {48158, 80}, {48125, 80}, {64843, 80}, {64901, 80} };
int talentPriest[34][3] = { {53005, 70, 47540}, {53006, 75, 53005}, {53007, 80, 53006}, {19238, 26, 19236}, {19240, 34, 19238}, {19241, 42, 19240}, {19242, 50, 19241}, {19243, 58, 19242}, {25437, 66, 19243}, {48172, 73, 25437}, {48173, 80, 48172}, {27870, 50, 724}, {27871, 60, 27870}, {28275, 70, 27871}, {48086, 75, 28275}, {48087, 80, 48086}, {34863, 56, 34861}, {34864, 60, 34863}, {34865, 65, 34864}, {34866, 70, 34865}, {48088, 75, 34866}, {48089, 80, 48088}, {17311, 28, 15407}, {17312, 36, 17311}, {17313, 44, 17312}, {17314, 52, 17313}, {18807, 60, 17314}, {25387, 68, 18807}, {48155, 74, 25387}, {48156, 80, 48155}, {34916, 60, 34914}, {34917, 70, 34916}, {48159, 75, 34917}, {48160, 80, 48159} };

int mountSkill[5][3] = {
    {33388, 20, true}, // Apprentice Riding, Level 20
    {33391, 40, true}, // Journeyman Riding, Level 40
    {34090, 60, true}, // Expert Riding, Level 60
    {34091, 70, false}, // Artisan Flying, Level 70
    {54197, 77, false} // Cold Weather Flying, Level 77
};

int mountSpell[79][4] = {
    {458, 33388, RACE_HUMAN, TEAM_ALLIANCE}, // Brown Horse, Requires Apprentice Riding, Human, Alliance
    {472, 33388, RACE_HUMAN, TEAM_ALLIANCE}, // Pinto, Requires Apprentice Riding, Human, Alliance
    {6648, 33388, RACE_HUMAN, TEAM_ALLIANCE}, // Chestnut Mare, Requires Apprentice Riding, Human, Alliance
    {23227, 33391, RACE_HUMAN, TEAM_ALLIANCE}, // Swift Palomino, Requires Journeyman Riding, Human, Alliance
    {23228, 33391, RACE_HUMAN, TEAM_ALLIANCE}, // Swift White Steed, Requires Journeyman Riding, Human, Alliance
    {23229, 33391, RACE_HUMAN, TEAM_ALLIANCE}, // Swift Brown Steed, Requires Journeyman Riding, Human, Alliance
    {8394, 33388, RACE_NIGHTELF, TEAM_ALLIANCE}, // Striped Frostsaber, Requires Apprentice Riding, Night Elf, Alliance
    {10789, 33388, RACE_NIGHTELF, TEAM_ALLIANCE}, // Spotted Frostsaber, Requires Apprentice Riding, Night Elf, Alliance
    {10793, 33388, RACE_NIGHTELF, TEAM_ALLIANCE}, // Striped Nightsaber, Requires Apprentice Riding, Night Elf, Alliance
    {66847, 33388, RACE_NIGHTELF, TEAM_ALLIANCE}, // Striped Dawnsaber, Requires Apprentice Riding, Night Elf, Alliance
    {23221, 33391, RACE_NIGHTELF, TEAM_ALLIANCE}, // Swift Frostsaber, Requires Journeyman Riding, Night Elf, Alliance
    {23219, 33391, RACE_NIGHTELF, TEAM_ALLIANCE}, // Swift Mistsaber, Requires Journeyman Riding, Night Elf, Alliance
    {23338, 33391, RACE_NIGHTELF, TEAM_ALLIANCE}, // Swift Stormsaber, Requires Journeyman Riding, Night Elf, Alliance
    {10873, 33388, RACE_GNOME, TEAM_ALLIANCE}, // Red Mechanostrider, Requires Apprentice Riding, Gnome, Alliance
    {10969, 33388, RACE_GNOME, TEAM_ALLIANCE}, // Blue Mechanostrider, Requires Apprentice Riding, Gnome, Alliance
    {17453, 33388, RACE_GNOME, TEAM_ALLIANCE}, // Green Mechanostrider, Requires Apprentice Riding, Gnome, Alliance
    {17454, 33388, RACE_GNOME, TEAM_ALLIANCE}, // Unpainted Mechanostrider, Requires Apprentice Riding, Gnome, Alliance
    {23222, 33391, RACE_GNOME, TEAM_ALLIANCE}, // Swift Yellow Mechanostrider, Requires Journeyman Riding, Gnome, Alliance
    {23223, 33391, RACE_GNOME, TEAM_ALLIANCE}, // Swift White Mechanostrider, Requires Journeyman Riding, Gnome, Alliance
    {23225, 33391, RACE_GNOME, TEAM_ALLIANCE}, // Swift Green Mechanostrider, Requires Journeyman Riding, Gnome, Alliance
    {6777, 33388, RACE_DWARF, TEAM_ALLIANCE}, // Gray Ram, Requires Apprentice Riding, Dwarf, Alliance
    {6898, 33388, RACE_DWARF, TEAM_ALLIANCE}, // White Ram, Requires Apprentice Riding, Dwarf, Alliance
    {6899, 33388, RACE_DWARF, TEAM_ALLIANCE}, // Brown Ram, Requires Apprentice Riding, Dwarf, Alliance
    {23238, 33391, RACE_DWARF, TEAM_ALLIANCE}, // Swift Brown Ram, Requires Journeyman Riding, Dwarf, Alliance
    {23239, 33391, RACE_DWARF, TEAM_ALLIANCE}, // Swift Gray Ram, Requires Journeyman Riding, Dwarf, Alliance
    {23240, 33391, RACE_DWARF, TEAM_ALLIANCE}, // Swift White Ram, Requires Journeyman Riding, Dwarf, Alliance
    {34406, 33388, RACE_DRAENEI, TEAM_ALLIANCE}, // Brown Elekk, Requires Apprentice Riding, Draenei, Alliance
    {35710, 33388, RACE_DRAENEI, TEAM_ALLIANCE}, // Gray Elekk, Requires Apprentice Riding, Draenei, Alliance
    {35711, 33388, RACE_DRAENEI, TEAM_ALLIANCE}, // Purple Elekk, Requires Apprentice Riding, Draenei, Alliance
    {35712, 33391, RACE_DRAENEI, TEAM_ALLIANCE}, // Great Green Elekk, Requires Journeyman Riding, Draenei, Alliance
    {35713, 33391, RACE_DRAENEI, TEAM_ALLIANCE}, // Great Blue Elekk, Requires Journeyman Riding, Draenei, Alliance
    {35714, 33391, RACE_DRAENEI, TEAM_ALLIANCE}, // Great Purple Elekk, Requires Journeyman Riding, Draenei, Alliance
    {32239, 34090, 0, TEAM_ALLIANCE}, // Ebon Gryphon, Requires Expert Riding, Any Race, Alliance
    {32240, 34090, 0, TEAM_ALLIANCE}, // Snowy Gryphon, Requires Expert Riding, Any Race, Alliance
    {32235, 34090, 0, TEAM_ALLIANCE}, // Golden Gryphon, Requires Expert Riding, Any Race, Alliance
    {32242, 34091, 0, TEAM_ALLIANCE}, // Swift Blue Gryphon, Requires Artisan Flying, Any Race, Alliance
    {32289, 34091, 0, TEAM_ALLIANCE}, // Swift Red Gryphon, Requires Artisan Flying, Any Race, Alliance
    {32290, 34091, 0, TEAM_ALLIANCE}, // Swift Green Gryphon, Requires Artisan Flying, Any Race, Alliance
    {32292, 34091, 0, TEAM_ALLIANCE}, // Swift Purple Gryphon, Requires Artisan Flying, Any Race, Alliance

    {580, 33388, RACE_ORC, TEAM_HORDE}, // Timber Wolf, Requires Apprentice Riding, Orc, Horde
    {6653, 33388, RACE_ORC, TEAM_HORDE}, // Dire Wolf, Requires Apprentice Riding, Orc, Horde
    {6654, 33388, RACE_ORC, TEAM_HORDE}, // Brown Wolf, Requires Apprentice Riding, Orc, Horde
    {64658, 33388, RACE_ORC, TEAM_HORDE}, //Black Wolf, Requires Apprentice Riding, Orc, Horde
    {23250, 33391, RACE_ORC, TEAM_HORDE}, // Swift Brown Wolf, Requires Journeyman Riding, Orc, Horde
    {23251, 33391, RACE_ORC, TEAM_HORDE}, // Swift Timber Wolf, Requires Journeyman Riding, Orc, Horde
    {23252, 33391, RACE_ORC, TEAM_HORDE}, // Swift Gray Wolf, Requires Journeyman Riding, Orc, Horde
    {8395, 33388, RACE_TROLL, TEAM_HORDE}, // Emerald Raptor, Requires Apprentice Riding, Troll, Horde
    {10796, 33388, RACE_TROLL, TEAM_HORDE}, // Turquoise Raptor, Requires Apprentice Riding, Troll, Horde
    {10799, 33388, RACE_TROLL, TEAM_HORDE}, // Violet Raptor, Requires Apprentice Riding, Troll, Horde
    {23241, 33391, RACE_TROLL, TEAM_HORDE}, // Swift Blue Raptor, Requires Journeyman Riding, Troll, Horde
    {23242, 33391, RACE_TROLL, TEAM_HORDE}, // Swift Olive Raptor, Requires Journeyman Riding, Troll, Horde
    {23243, 33391, RACE_TROLL, TEAM_HORDE}, // Swift Orange Raptor, Requires Journeyman Riding, Troll, Horde
    {17462, 33388, RACE_UNDEAD_PLAYER, TEAM_HORDE}, // Red Skeletal Horse, Requires Apprentice Riding, Undead, Horde
    {17463, 33388, RACE_UNDEAD_PLAYER, TEAM_HORDE}, // Blue Skeletal Horse, Requires Apprentice Riding, Undead, Horde
    {17464, 33388, RACE_UNDEAD_PLAYER, TEAM_HORDE}, // Brown Skeletal Horse, Requires Apprentice Riding, Undead, Horde
    {64977, 33388, RACE_UNDEAD_PLAYER, TEAM_HORDE}, // Black Skeletal Horse, Requires Apprentice Riding, Undead, Horde
    {17465, 33391, RACE_UNDEAD_PLAYER, TEAM_HORDE}, // Green Skeletal Warhorse, Requires Journeyman Riding, Undead, Horde
    {23246, 33391, RACE_UNDEAD_PLAYER, TEAM_HORDE}, // Purple Skeletal Warhorse, Requires Journeyman Riding, Undead, Horde
    {66846, 33391, RACE_UNDEAD_PLAYER, TEAM_HORDE}, // Ochre Skeletal Warhorse, Requires Journeyman Riding, Undead, Horde
    {18989, 33388, RACE_TAUREN, TEAM_HORDE}, // Gray Kodo, Requires Apprentice Riding, Tauren, Horde
    {18990, 33388, RACE_TAUREN, TEAM_HORDE}, // Brown Kodo, Requires Apprentice Riding, Tauren, Horde
    {64657, 33388, RACE_TAUREN, TEAM_HORDE}, // White Kodo, Requires Apprentice Riding, Tauren, Horde
    {23247, 33391, RACE_TAUREN, TEAM_HORDE}, // Great White Kodo, Requires Journeyman Riding, Tauren, Horde
    {23248, 33391, RACE_TAUREN, TEAM_HORDE}, // Great Gray Kodo, Requires Journeyman Riding, Tauren, Horde
    {23249, 33391, RACE_TAUREN, TEAM_HORDE}, // Great Brown Kodo, Requires Journeyman Riding, Tauren, Horde
    {34795, 33388, RACE_BLOODELF, TEAM_HORDE}, // Red Hawkstrider, Requires Apprentice Riding, Blood Elf, Horde
    {35018, 33388, RACE_BLOODELF, TEAM_HORDE}, // Purple Hawkstrider, Requires Apprentice Riding, Blood Elf, Horde
    {35020, 33388, RACE_BLOODELF, TEAM_HORDE}, // Blue Hawkstrider, Requires Apprentice Riding, Blood Elf, Horde
    {35022, 33388, RACE_BLOODELF, TEAM_HORDE}, // Black Hawkstrider, Requires Apprentice Riding, Blood Elf, Horde
    {33660, 33391, RACE_BLOODELF, TEAM_HORDE}, // Swift Pink Hawkstrider, Requires Journeyman Riding, Blood Elf, Horde
    {35025, 33391, RACE_BLOODELF, TEAM_HORDE}, // Swift Green Hawkstrider, Requires Journeyman Riding, Blood Elf, Horde
    {35027, 33391, RACE_BLOODELF, TEAM_HORDE}, // Swift Purple Hawkstrider, Requires Journeyman Riding, Blood Elf, Horde
    {32243, 34090, 0, TEAM_HORDE}, // Tawny Wind Rider, Requires Expert Riding, Any Race, Horde
    {32244, 34090, 0, TEAM_HORDE}, // Blue Wind Rider, Requires Expert Riding, Any Race, Horde
    {32245, 34090, 0, TEAM_HORDE}, // Green Wind Rider, Requires Expert Riding, Any Race, Horde
    {32246, 34091, 0, TEAM_HORDE}, // Swift Red Wind Rider, Requires Artisan Flying, Any Race, Horde
    {32295, 34091, 0, TEAM_HORDE}, // Swift Green Wind Rider, Requires Artisan Flying, Any Race, Horde
    {32296, 34091, 0, TEAM_HORDE}, // Swift Yellow Wind Rider, Requires Artisan Flying, Any Race, Horde
    {32297, 34091, 0, TEAM_HORDE}  // Swift Purple Wind Rider, Requires Artisan Flying, Any Race, Horde
};

class Kickstarter : public CreatureScript
{
    public:
        Kickstarter() : CreatureScript("Kickstarter") { }

        void OnLogin(Player* player)
        {
            ChatHandler(player->GetSession()).SendSysMessage("This server is running the |cff4CFF00Kickstarter |rmodule.");
        }

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
                ClearGossipMenuFor(player);

                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want some armor", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+1);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want accessories", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+2);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want weapons", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+7);

                SendGossipMenuFor(player, TEXT_KICKSTARTER+1, creature->GetGUID());
            }

            // Equipment: Armor
            if (action == ID_EQUIPMENT+1)
            {
                switch (player->getClass())
                {
                    case CLASS_PRIEST:
                    case CLASS_MAGE:
                    case CLASS_WARLOCK:
                        player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_EQUIPMENT);
                        break;
                    case CLASS_DRUID:
                    case CLASS_ROGUE:
                        player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_EQUIPMENT+1);
                        break;
                    case CLASS_SHAMAN:
                    case CLASS_HUNTER:
                        player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_EQUIPMENT+2);
                        break;
                    case CLASS_PALADIN:
                    case CLASS_WARRIOR:
                    case CLASS_DEATH_KNIGHT:
                        player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_EQUIPMENT+3);
                        break;
                }
            }

            // Equipment: Accessories
            if (action == ID_EQUIPMENT+2)
            {
                ClearGossipMenuFor(player);

                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Cloaks", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+3);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Amulets", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+4);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Rings", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+5);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Trinkets", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+6);

                SendGossipMenuFor(player, TEXT_KICKSTARTER+1, creature->GetGUID());
            }

            // Accessories: Cloaks
            if (action == ID_EQUIPMENT+3)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_ACCESSORIES);
            }

            // Accessories: Cloaks
            if (action == ID_EQUIPMENT+4)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_ACCESSORIES+1);
            }

            // Accessories: Cloaks
            if (action == ID_EQUIPMENT+5)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_ACCESSORIES+2);
            }

            // Accessories: Cloaks
            if (action == ID_EQUIPMENT+6)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_ACCESSORIES+3);
            }

            // Equipment: Weapon
            if (action == ID_EQUIPMENT+7)
            {
                ClearGossipMenuFor(player);

                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Daggers", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+8);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Fist Weapons", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+9);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "One-Handed Axes", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+10);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "One-Handed Maces", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+11);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "One-Handed Swords", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+12);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Polearms", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+13);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Staves", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+14);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Two-Handed Axes", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+15);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Two-Handed Maces", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+16);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Two-Handed Swords", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+17);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Bows", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+18);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Crossbows", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+19);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Guns", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+20);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Thrown", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+21);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Wands", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+22);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Off-Hand Frills", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+23);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Shields", GOSSIP_SENDER_MAIN, ID_EQUIPMENT+24);

                SendGossipMenuFor(player, TEXT_KICKSTARTER+1, creature->GetGUID());
            }

            // Weapons: Daggers
            if (action == ID_EQUIPMENT+8)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_WEAPONS);
            }

            // Weapons: Fist Weapons
            if (action == ID_EQUIPMENT+9)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_WEAPONS+1);
            }

            // Weapons: One-Handed Axes
            if (action == ID_EQUIPMENT+10)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_WEAPONS+2);
            }

            // Weapons: One-Handed Maces
            if (action == ID_EQUIPMENT+11)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_WEAPONS+3);
            }

            // Weapons: One-Handed Swords
            if (action == ID_EQUIPMENT+12)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_WEAPONS+4);
            }

            // Weapons: Polearms
            if (action == ID_EQUIPMENT+13)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_WEAPONS+5);
            }

            // Weapons: Staves
            if (action == ID_EQUIPMENT+14)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_WEAPONS+6);
            }

            // Weapons: Two-Handed Axes
            if (action == ID_EQUIPMENT+15)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_WEAPONS+7);
            }

            // Weapons: Two-Handed Maces
            if (action == ID_EQUIPMENT+16)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_WEAPONS+8);
            }

            // Weapons: Two-Handed Swords
            if (action == ID_EQUIPMENT+17)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_WEAPONS+9);
            }

            // Weapons: Bows
            if (action == ID_EQUIPMENT+18)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_WEAPONS+10);
            }

            // Weapons: Crossbows
            if (action == ID_EQUIPMENT+19)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_WEAPONS+11);
            }

            // Weapons: Guns
            if (action == ID_EQUIPMENT+20)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_WEAPONS+12);
            }

            // Weapons: Thrown
            if (action == ID_EQUIPMENT+21)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_WEAPONS+13);
            }

            // Weapons: Wands
            if (action == ID_EQUIPMENT+22)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_WEAPONS+14);
            }

            // Weapons: Off-Hand Frills
            if (action == ID_EQUIPMENT+23)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_WEAPONS+15);
            }

            // Weapons: Shields
            if (action == ID_EQUIPMENT+24)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_WEAPONS+16);
            }

            // Gems
            if (action == ID_GEMS)
            {
                ClearGossipMenuFor(player);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Meta", GOSSIP_SENDER_MAIN, ID_GEMS+1);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Red", GOSSIP_SENDER_MAIN, ID_GEMS+2);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Blue", GOSSIP_SENDER_MAIN, ID_GEMS+3);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Yellow", GOSSIP_SENDER_MAIN, ID_GEMS+4);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Purple", GOSSIP_SENDER_MAIN, ID_GEMS+5);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Green", GOSSIP_SENDER_MAIN, ID_GEMS+6);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Orange", GOSSIP_SENDER_MAIN, ID_GEMS+7);
                SendGossipMenuFor(player, TEXT_KICKSTARTER+1, creature->GetGUID());
            }

            // Gems: Meta
            if (action == ID_GEMS+1)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_GEMS);
            }

            // Gems: Red
            if (action == ID_GEMS+2)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_GEMS+1);
            }

            // Gems: Blue
            if (action == ID_GEMS+3)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_GEMS+2);
            }

            // Gems: Yellow
            if (action == ID_GEMS+4)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_GEMS+3);
            }

            // Gems: Purple
            if (action == ID_GEMS+5)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_GEMS+4);
            }

            // Gems: Green
            if (action == ID_GEMS+6)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_GEMS+5);
            }

            // Gems: Orange
            if (action == ID_GEMS+7)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_GEMS+6);
            }

            // Glyphs
            if (action == ID_GLYPHS)
            {
                switch (player->getClass())
                {
                    case CLASS_PRIEST:
                        player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_GLYPHS);
                        break;
                    case CLASS_PALADIN:
                        player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_GLYPHS+1);
                        break;
                    case CLASS_WARRIOR:
                        player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_GLYPHS+2);
                        break;
                    case CLASS_MAGE:
                        player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_GLYPHS+3);
                        break;
                    case CLASS_WARLOCK:
                        player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_GLYPHS+4);
                        break;
                    case CLASS_SHAMAN:
                        player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_GLYPHS+5);
                        break;
                    case CLASS_DRUID:
                        player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_GLYPHS+6);
                        break;
                    case CLASS_HUNTER:
                        player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_GLYPHS+7);
                        break;
                    case CLASS_ROGUE:
                        player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_GLYPHS+8);
                        break;
                    case CLASS_DEATH_KNIGHT:
                        player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_GLYPHS+9);
                        break;
                }
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
                        /*// Learn all spells
                        for (int s : spellPaladin)
                            player->learnSpell(s);

                        // Holy Shock
                        if (player->HasSpell(20473))
                        {
                            player->learnSpell(20929);
                            player->learnSpell(20930);
                            player->learnSpell(27174);
                            player->learnSpell(33072);
                            player->learnSpell(48824);
                            player->learnSpell(48825);
                        }

                        // Blessing of Sanctuary
                        if (player->HasSpell(20911))
                            player->learnSpell(25899);

                        // Holy Shield
                        if (player->HasSpell(20925))
                        {
                            player->learnSpell(20927);
                            player->learnSpell(20928);
                            player->learnSpell(27179);
                            player->learnSpell(48951);
                            player->learnSpell(48952);
                        }
                        // Avenger's Shield
                        if (player->HasSpell(31935))
                        {
                            player->learnSpell(32699);
                            player->learnSpell(32700);
                            player->learnSpell(48826);
                            player->learnSpell(48827);
                        }*/

                        // Seal of Vengeance (Alliance), Seal of Corruption (Horde)
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
                    /*case CLASS_WARRIOR:
                        // Learn all spells
                        for (int s : spellWarrior)
                            player->learnSpell(s);

                        // Mortal Strike
                        if (player->HasSpell(12294))
                        {
                            player->learnSpell(21551);
                            player->learnSpell(21552);
                            player->learnSpell(21553);
                            player->learnSpell(25248);
                            player->learnSpell(30330);
                            player->learnSpell(47485);
                            player->learnSpell(47486);
                        }
                        // Devastate
                        if (player->HasSpell(20243))
                        {
                            player->learnSpell(30016);
                            player->learnSpell(30022);
                            player->learnSpell(47497);
                            player->learnSpell(47498);
                        }

                        break;
                    case CLASS_MAGE:
                        // Learn all spells
                        for (int s : spellMage)
                            player->learnSpell(s);

                        // Arcane Barrage
                        if (player->HasSpell(44425))
                        {
                            player->learnSpell(44780);
                            player->learnSpell(44781);
                        }
                        // Pyroblast
                        if (player->HasSpell(11366))
                        {
                            player->learnSpell(12505);
                            player->learnSpell(12522);
                            player->learnSpell(12523);
                            player->learnSpell(12524);
                            player->learnSpell(12525);
                            player->learnSpell(12526);
                            player->learnSpell(18809);
                            player->learnSpell(27132);
                            player->learnSpell(33938);
                            player->learnSpell(42890);
                            player->learnSpell(42891);
                        }
                        // Blast Wave
                        if (player->HasSpell(11113))
                        {
                            player->learnSpell(13018);
                            player->learnSpell(13019);
                            player->learnSpell(13020);
                            player->learnSpell(13021);
                            player->learnSpell(27133);
                            player->learnSpell(33933);
                            player->learnSpell(42944);
                            player->learnSpell(42945);
                        }
                        // Dragon's Breath
                        if (player->HasSpell(31661))
                        {
                            player->learnSpell(33041);
                            player->learnSpell(33042);
                            player->learnSpell(33043);
                            player->learnSpell(42949);
                            player->learnSpell(42950);
                        }
                        // Living Bomb
                        if (player->HasSpell(44457))
                        {
                            player->learnSpell(55359);
                            player->learnSpell(55360);
                        }
                        // Ice Barrier
                        if (player->HasSpell(11426))
                        {
                            player->learnSpell(13031);
                            player->learnSpell(13032);
                            player->learnSpell(13033);
                            player->learnSpell(27134);
                            player->learnSpell(33405);
                            player->learnSpell(43038);
                            player->learnSpell(43039);
                        }

                        break;
                    case CLASS_WARLOCK:
                        // Learn all spells
                        for (int s : spellWarlock)
                            player->learnSpell(s);

                        // Dark Pact
                        if (player->HasSpell(18220))
                        {
                            player->learnSpell(18937);
                            player->learnSpell(18938);
                            player->learnSpell(27265);
                            player->learnSpell(59092);
                        }
                        // Unstable Affliction
                        if (player->HasSpell(30108))
                        {
                            player->learnSpell(30404);
                            player->learnSpell(30405);
                            player->learnSpell(47841);
                            player->learnSpell(47843);
                        }
                        // Haunt
                        if (player->HasSpell(48181))
                        {
                            player->learnSpell(59161);
                            player->learnSpell(59163);
                            player->learnSpell(59164);
                        }
                        // Shadowburn
                        if (player->HasSpell(17877))
                        {
                            player->learnSpell(18867);
                            player->learnSpell(18868);
                            player->learnSpell(18869);
                            player->learnSpell(18870);
                            player->learnSpell(18871);
                            player->learnSpell(27263);
                            player->learnSpell(30546);
                            player->learnSpell(47826);
                            player->learnSpell(47827);
                        }
                        // Shadowfury
                        if (player->HasSpell(30283))
                        {
                            player->learnSpell(30413);
                            player->learnSpell(30414);
                            player->learnSpell(47846);
                            player->learnSpell(47847);
                        }
                        // Chaos Bolt
                        if (player->HasSpell(50796))
                        {
                            player->learnSpell(59170);
                            player->learnSpell(59171);
                            player->learnSpell(59172);
                        }
                        
                        break;
                    case CLASS_SHAMAN:
                        // Learn all spells
                        for (int s : spellShaman)
                            player->learnSpell(s);

                        // Totem of Wrath
                        if (player->HasSpell(30706))
                        {
                            player->learnSpell(57720);
                            player->learnSpell(57721);
                            player->learnSpell(57722);
                        }
                        // Thunderstorm
                        if (player->HasSpell(51490))
                        {
                            player->learnSpell(59156);
                            player->learnSpell(59158);
                            player->learnSpell(59159);
                        }
                        // Earth Shield
                        if (player->HasSpell(974))
                        {
                            player->learnSpell(32593);
                            player->learnSpell(32594);
                            player->learnSpell(49283);
                            player->learnSpell(49284);
                        }
                        // Riptide
                        if (player->HasSpell(61295))
                        {
                            player->learnSpell(61299);
                            player->learnSpell(61300);
                            player->learnSpell(61301);
                        }
                        break;
                    case CLASS_DRUID:
                        // Learn all spells
                        for (int s : spellDruid)
                            player->learnSpell(s);

                        // Insect Swarm
                        if (player->HasSpell(5570))
                        {
                            player->learnSpell(24974);
                            player->learnSpell(24975);
                            player->learnSpell(24976);
                            player->learnSpell(24977);
                            player->learnSpell(27013);
                            player->learnSpell(48468);
                        }
                        // Typhoon
                        if (player->HasSpell(50516))
                        {
                            player->learnSpell(53223);
                            player->learnSpell(53225);
                            player->learnSpell(53226);
                            player->learnSpell(61384);
                        }
                        // Starfall
                        if (player->HasSpell(48505))
                        {
                            player->learnSpell(53199);
                            player->learnSpell(53200);
                            player->learnSpell(53201);
                        }
                        // Mangle (Bear)
                        if (player->HasSpell(33878))
                        {
                            player->learnSpell(33986);
                            player->learnSpell(33987);
                            player->learnSpell(48563);
                            player->learnSpell(48564);
                        }
                        // Mangle (Cat)
                        if (player->HasSpell(33876))
                        {
                            player->learnSpell(33982);
                            player->learnSpell(33983);
                            player->learnSpell(48565);
                            player->learnSpell(48566);
                        }
                        // Wild Growth
                        if (player->HasSpell(48438))
                        {
                            player->learnSpell(53248);
                            player->learnSpell(53249);
                            player->learnSpell(53251);
                        }
                        break;
                    case CLASS_HUNTER:
                        // Learn all spells
                        for (int s : spellHunter)
                            player->learnSpell(s);

                        // Aimed Shot
                        if (player->HasSpell(19434))
                        {
                            player->learnSpell(20900);
                            player->learnSpell(20901);
                            player->learnSpell(20902);
                            player->learnSpell(20903);
                            player->learnSpell(20904);
                            player->learnSpell(27065);
                            player->learnSpell(49049);
                            player->learnSpell(49050);
                        }
                        // Counterattack
                        if (player->HasSpell(19306))
                        {
                            player->learnSpell(20909);
                            player->learnSpell(20910);
                            player->learnSpell(27067);
                            player->learnSpell(48998);
                            player->learnSpell(48999);
                        }
                        // Wyvern Sting
                        if (player->HasSpell(19386))
                        {
                            player->learnSpell(24132);
                            player->learnSpell(24133);
                            player->learnSpell(27068);
                            player->learnSpell(49011);
                            player->learnSpell(49012);
                        }
                        // Black Arrow
                        if (player->HasSpell(3674))
                        {
                            player->learnSpell(63668);
                            player->learnSpell(63669);
                            player->learnSpell(63670);
                            player->learnSpell(63671);
                            player->learnSpell(63672);
                        }
                        // Explosive Shot
                        if (player->HasSpell(53301))
                        {
                            player->learnSpell(60051);
                            player->learnSpell(60052);
                            player->learnSpell(60053);
                        }
                        break;
                    case CLASS_ROGUE:
                        // Learn all spells
                        for (int s : spellRogue)
                            player->learnSpell(s);

                        // Mutilate
                        if (player->HasSpell(1329))
                        {
                            player->learnSpell(34411);
                            player->learnSpell(34412);
                            player->learnSpell(34413);
                            player->learnSpell(48663);
                            player->learnSpell(48666);
                        }
                        // Hemorrhage
                        if (player->HasSpell(16511))
                        {
                            player->learnSpell(17347);
                            player->learnSpell(17348);
                            player->learnSpell(26864);
                            player->learnSpell(48660);
                        }
                        break;
                    case CLASS_DEATH_KNIGHT:
                        // Learn all spells
                        for (int s : spellDeathKnight)
                            player->learnSpell(s);

                        // Heart Strike
                        if (player->HasSpell(55050))
                        {
                            player->learnSpell(55258);
                            player->learnSpell(55259);
                            player->learnSpell(55260);
                            player->learnSpell(55261);
                            player->learnSpell(55262);
                        }
                        // Frost Strike
                        if (player->HasSpell(49143))
                        {
                            player->learnSpell(51416);
                            player->learnSpell(51417);
                            player->learnSpell(51418);
                            player->learnSpell(51419);
                            player->learnSpell(55268);
                        }
                        // Howling Blast
                        if (player->HasSpell(49184))
                        {
                            player->learnSpell(51409);
                            player->learnSpell(51410);
                            player->learnSpell(51411);
                        }
                        // Corpse Explosion
                        if (player->HasSpell(49158))
                        {
                            player->learnSpell(51325);
                            player->learnSpell(51326);
                            player->learnSpell(51327);
                            player->learnSpell(51328);
                        }
                        // Scourge Strike
                        if (player->HasSpell(55090))
                        {
                            player->learnSpell(55265);
                            player->learnSpell(55270);
                            player->learnSpell(55271);
                        }
                        break;*/
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
                        if (!player->HasSpell(PROFICIENCY_ONE_HANDED_MACES))
                            player->learnSpell(PROFICIENCY_ONE_HANDED_MACES);
                        if (!player->HasSpell(PROFICIENCY_DAGGERS))
                            player->learnSpell(PROFICIENCY_DAGGERS);
                        if (!player->HasSpell(PROFICIENCY_STAVES))
                            player->learnSpell(PROFICIENCY_STAVES);
                        if (!player->HasSpell(PROFICIENCY_WANDS))
                            player->learnSpell(PROFICIENCY_WANDS);
                        break;
                    case CLASS_PALADIN:
                        if (!player->HasSpell(PROFICIENCY_MAIL))
                            player->learnSpell(PROFICIENCY_MAIL);
                        if (!player->HasSpell(PROFICIENCY_PLATE_MAIL))
                            player->learnSpell(PROFICIENCY_PLATE_MAIL);
                        if (!player->HasSpell(PROFICIENCY_POLEARMS))
                            player->learnSpell(PROFICIENCY_POLEARMS);
                        if (!player->HasSpell(PROFICIENCY_ONE_HANDED_MACES))
                            player->learnSpell(PROFICIENCY_ONE_HANDED_MACES);
                        if (!player->HasSpell(PROFICIENCY_TWO_HANDED_MACES))
                            player->learnSpell(PROFICIENCY_TWO_HANDED_MACES);
                        if (!player->HasSpell(PROFICIENCY_ONE_HANDED_SWORDS))
                            player->learnSpell(PROFICIENCY_ONE_HANDED_SWORDS);
                        if (!player->HasSpell(PROFICIENCY_ONE_HANDED_AXES))
                            player->learnSpell(PROFICIENCY_ONE_HANDED_AXES);
                        if (!player->HasSpell(PROFICIENCY_TWO_HANDED_AXES))
                            player->learnSpell(PROFICIENCY_TWO_HANDED_AXES);
                        if (!player->HasSpell(PROFICIENCY_TWO_HANDED_SWORDS))
                            player->learnSpell(PROFICIENCY_TWO_HANDED_SWORDS);
                        if (!player->HasSpell(PROFICIENCY_SHIELD))
                            player->learnSpell(PROFICIENCY_SHIELD);
                        if (!player->HasSpell(PROFICIENCY_PARRY))
                            player->learnSpell(PROFICIENCY_PARRY);
                        if (!player->HasSpell(PROFICIENCY_BLOCK))
                            player->learnSpell(PROFICIENCY_BLOCK);
                        break;
                    case CLASS_WARRIOR:
                        if (!player->HasSpell(PROFICIENCY_MAIL))
                            player->learnSpell(PROFICIENCY_MAIL);
                        if (!player->HasSpell(PROFICIENCY_PLATE_MAIL))
                            player->learnSpell(PROFICIENCY_PLATE_MAIL);
                        if (!player->HasSpell(PROFICIENCY_POLEARMS))
                            player->learnSpell(PROFICIENCY_POLEARMS);
                        if (!player->HasSpell(PROFICIENCY_ONE_HANDED_MACES))
                            player->learnSpell(PROFICIENCY_ONE_HANDED_MACES);
                        if (!player->HasSpell(PROFICIENCY_TWO_HANDED_MACES))
                            player->learnSpell(PROFICIENCY_TWO_HANDED_MACES);
                        if (!player->HasSpell(PROFICIENCY_ONE_HANDED_SWORDS))
                            player->learnSpell(PROFICIENCY_ONE_HANDED_SWORDS);
                        if (!player->HasSpell(PROFICIENCY_ONE_HANDED_AXES))
                            player->learnSpell(PROFICIENCY_ONE_HANDED_AXES);
                        if (!player->HasSpell(PROFICIENCY_TWO_HANDED_SWORDS))
                            player->learnSpell(PROFICIENCY_TWO_HANDED_SWORDS);
                        if (!player->HasSpell(PROFICIENCY_DUAL_WIELD))
                            player->learnSpell(PROFICIENCY_DUAL_WIELD);
                        if (!player->HasSpell(PROFICIENCY_DAGGERS))
                            player->learnSpell(PROFICIENCY_DAGGERS);
                        if (!player->HasSpell(PROFICIENCY_STAVES))
                            player->learnSpell(PROFICIENCY_STAVES);
                        if (!player->HasSpell(PROFICIENCY_FIST_WEAPONS))
                            player->learnSpell(PROFICIENCY_FIST_WEAPONS);
                        if (!player->HasSpell(PROFICIENCY_BOWS))
                            player->learnSpell(PROFICIENCY_BOWS);
                        if (!player->HasSpell(PROFICIENCY_CROSSBOWS))
                            player->learnSpell(PROFICIENCY_CROSSBOWS);
                        if (!player->HasSpell(PROFICIENCY_GUNS))
                            player->learnSpell(PROFICIENCY_GUNS);
                        if (!player->HasSpell(PROFICIENCY_SHIELD))
                            player->learnSpell(PROFICIENCY_SHIELD);
                        if (!player->HasSpell(PROFICIENCY_PARRY))
                            player->learnSpell(PROFICIENCY_PARRY);
                        if (!player->HasSpell(PROFICIENCY_BLOCK))
                            player->learnSpell(PROFICIENCY_BLOCK);
                        break;
                    case CLASS_MAGE:
                        if (!player->HasSpell(PROFICIENCY_ONE_HANDED_SWORDS))
                            player->learnSpell(PROFICIENCY_ONE_HANDED_SWORDS);
                        if (!player->HasSpell(PROFICIENCY_DAGGERS))
                            player->learnSpell(PROFICIENCY_DAGGERS);
                        if (!player->HasSpell(PROFICIENCY_STAVES))
                            player->learnSpell(PROFICIENCY_STAVES);
                        if (!player->HasSpell(PROFICIENCY_WANDS))
                            player->learnSpell(PROFICIENCY_WANDS);
                        break;
                    case CLASS_WARLOCK:
                        if (!player->HasSpell(PROFICIENCY_ONE_HANDED_SWORDS))
                            player->learnSpell(PROFICIENCY_ONE_HANDED_SWORDS);
                        if (!player->HasSpell(PROFICIENCY_DAGGERS))
                            player->learnSpell(PROFICIENCY_DAGGERS);
                        if (!player->HasSpell(PROFICIENCY_STAVES))
                            player->learnSpell(PROFICIENCY_STAVES);
                        if (!player->HasSpell(PROFICIENCY_WANDS))
                            player->learnSpell(PROFICIENCY_WANDS);
                        break;
                    case CLASS_SHAMAN:
                        if (!player->HasSpell(PROFICIENCY_MAIL))
                            player->learnSpell(PROFICIENCY_MAIL);
                        if (!player->HasSpell(PROFICIENCY_ONE_HANDED_MACES))
                            player->learnSpell(PROFICIENCY_ONE_HANDED_MACES);
                        if (!player->HasSpell(PROFICIENCY_TWO_HANDED_MACES))
                            player->learnSpell(PROFICIENCY_TWO_HANDED_MACES);
                        if (!player->HasSpell(PROFICIENCY_ONE_HANDED_AXES))
                            player->learnSpell(PROFICIENCY_ONE_HANDED_AXES);
                        if (!player->HasSpell(PROFICIENCY_TWO_HANDED_AXES))
                            player->learnSpell(PROFICIENCY_TWO_HANDED_AXES);
                        if (!player->HasSpell(PROFICIENCY_DAGGERS))
                            player->learnSpell(PROFICIENCY_DAGGERS);
                        if (!player->HasSpell(PROFICIENCY_STAVES))
                            player->learnSpell(PROFICIENCY_STAVES);
                        if (!player->HasSpell(PROFICIENCY_FIST_WEAPONS))
                            player->learnSpell(PROFICIENCY_FIST_WEAPONS);
                        if (!player->HasSpell(PROFICIENCY_SHIELD))
                            player->learnSpell(PROFICIENCY_SHIELD);
                        if (!player->HasSpell(PROFICIENCY_BLOCK))
                            player->learnSpell(PROFICIENCY_BLOCK);
                        break;
                    case CLASS_DRUID:
                        if (!player->HasSpell(PROFICIENCY_POLEARMS))
                            player->learnSpell(PROFICIENCY_POLEARMS);
                        if (!player->HasSpell(PROFICIENCY_ONE_HANDED_MACES))
                            player->learnSpell(PROFICIENCY_ONE_HANDED_MACES);
                        if (!player->HasSpell(PROFICIENCY_TWO_HANDED_MACES))
                            player->learnSpell(PROFICIENCY_TWO_HANDED_MACES);
                        if (!player->HasSpell(PROFICIENCY_DAGGERS))
                            player->learnSpell(PROFICIENCY_DAGGERS);
                        if (!player->HasSpell(PROFICIENCY_STAVES))
                            player->learnSpell(PROFICIENCY_STAVES);
                        if (!player->HasSpell(PROFICIENCY_FIST_WEAPONS))
                            player->learnSpell(PROFICIENCY_FIST_WEAPONS);
                        break;
                    case CLASS_HUNTER:
                        if (!player->HasSpell(PROFICIENCY_MAIL))
                            player->learnSpell(PROFICIENCY_MAIL);
                        if (!player->HasSpell(PROFICIENCY_POLEARMS))
                            player->learnSpell(PROFICIENCY_POLEARMS);
                        if (!player->HasSpell(PROFICIENCY_ONE_HANDED_SWORDS))
                            player->learnSpell(PROFICIENCY_ONE_HANDED_SWORDS);
                        if (!player->HasSpell(PROFICIENCY_ONE_HANDED_AXES))
                            player->learnSpell(PROFICIENCY_ONE_HANDED_AXES);
                        if (!player->HasSpell(PROFICIENCY_TWO_HANDED_AXES))
                            player->learnSpell(PROFICIENCY_TWO_HANDED_AXES);
                        if (!player->HasSpell(PROFICIENCY_TWO_HANDED_SWORDS))
                            player->learnSpell(PROFICIENCY_TWO_HANDED_SWORDS);
                        if (!player->HasSpell(PROFICIENCY_DUAL_WIELD))
                            player->learnSpell(PROFICIENCY_DUAL_WIELD);
                        if (!player->HasSpell(PROFICIENCY_DAGGERS))
                            player->learnSpell(PROFICIENCY_DAGGERS);
                        if (!player->HasSpell(PROFICIENCY_STAVES))
                            player->learnSpell(PROFICIENCY_STAVES);
                        if (!player->HasSpell(PROFICIENCY_FIST_WEAPONS))
                            player->learnSpell(PROFICIENCY_FIST_WEAPONS);
                        if (!player->HasSpell(PROFICIENCY_BOWS))
                            player->learnSpell(PROFICIENCY_BOWS);
                        if (!player->HasSpell(PROFICIENCY_CROSSBOWS))
                            player->learnSpell(PROFICIENCY_CROSSBOWS);
                        if (!player->HasSpell(PROFICIENCY_GUNS))
                            player->learnSpell(PROFICIENCY_GUNS);
                        if (!player->HasSpell(PROFICIENCY_PARRY))
                            player->learnSpell(PROFICIENCY_PARRY);
                        break;
                    case CLASS_ROGUE:
                        if (!player->HasSpell(PROFICIENCY_ONE_HANDED_MACES))
                            player->learnSpell(PROFICIENCY_ONE_HANDED_MACES);
                        if (!player->HasSpell(PROFICIENCY_ONE_HANDED_SWORDS))
                            player->learnSpell(PROFICIENCY_ONE_HANDED_SWORDS);
                        if (!player->HasSpell(PROFICIENCY_ONE_HANDED_AXES))
                            player->learnSpell(PROFICIENCY_ONE_HANDED_AXES);
                        if (!player->HasSpell(PROFICIENCY_DUAL_WIELD))
                            player->learnSpell(PROFICIENCY_DUAL_WIELD);
                        if (!player->HasSpell(PROFICIENCY_DAGGERS))
                            player->learnSpell(PROFICIENCY_DAGGERS);
                        if (!player->HasSpell(PROFICIENCY_FIST_WEAPONS))
                            player->learnSpell(PROFICIENCY_FIST_WEAPONS);
                        if (!player->HasSpell(PROFICIENCY_BOWS))
                            player->learnSpell(PROFICIENCY_BOWS);
                        if (!player->HasSpell(PROFICIENCY_CROSSBOWS))
                            player->learnSpell(PROFICIENCY_CROSSBOWS);
                        if (!player->HasSpell(PROFICIENCY_GUNS))
                            player->learnSpell(PROFICIENCY_GUNS);
                        if (!player->HasSpell(PROFICIENCY_PARRY))
                            player->learnSpell(PROFICIENCY_PARRY);
                        break;
                    case CLASS_DEATH_KNIGHT:
                        if (!player->HasSpell(PROFICIENCY_MAIL))
                            player->learnSpell(PROFICIENCY_MAIL);
                        if (!player->HasSpell(PROFICIENCY_PLATE_MAIL))
                            player->learnSpell(PROFICIENCY_PLATE_MAIL);
                        if (!player->HasSpell(PROFICIENCY_POLEARMS))
                            player->learnSpell(PROFICIENCY_POLEARMS);
                        if (!player->HasSpell(PROFICIENCY_ONE_HANDED_MACES))
                            player->learnSpell(PROFICIENCY_ONE_HANDED_MACES);
                        if (!player->HasSpell(PROFICIENCY_TWO_HANDED_MACES))
                            player->learnSpell(PROFICIENCY_TWO_HANDED_MACES);
                        if (!player->HasSpell(PROFICIENCY_ONE_HANDED_SWORDS))
                            player->learnSpell(PROFICIENCY_ONE_HANDED_SWORDS);
                        if (!player->HasSpell(PROFICIENCY_ONE_HANDED_AXES))
                            player->learnSpell(PROFICIENCY_ONE_HANDED_AXES);
                        if (!player->HasSpell(PROFICIENCY_TWO_HANDED_AXES))
                            player->learnSpell(PROFICIENCY_TWO_HANDED_AXES);
                        if (!player->HasSpell(PROFICIENCY_TWO_HANDED_SWORDS))
                            player->learnSpell(PROFICIENCY_TWO_HANDED_SWORDS);
                        if (!player->HasSpell(PROFICIENCY_DUAL_WIELD))
                            player->learnSpell(PROFICIENCY_DUAL_WIELD);
                        if (!player->HasSpell(PROFICIENCY_PARRY))
                            player->learnSpell(PROFICIENCY_PARRY);
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
