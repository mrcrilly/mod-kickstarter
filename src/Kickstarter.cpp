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

int spellDruid[]       = { 5176, 5185, 99, 339, 467, 740, 768, 769, 770, 774, 779, 780, 782, 783, 1058, 1062, 1066, 1075, 1079, 1082, 1126, 1430, 1735, 1822, 1823, 1824, 1850, 2090, 2091, 2637, 2782, 2893, 2908, 2912, 3029, 3627, 5177, 5178, 5179, 5180, 5186, 5187, 5188, 5189, 5195, 5196, 5201, 5209, 5211, 5215, 5217, 5221, 5225, 5229, 5232, 5234, 5487, 6756, 6778, 6780, 6785, 6787, 6793, 6795, 6798, 6800, 6807, 6808, 6809, 8903, 8905, 8907, 8910, 8914, 8918, 8921, 8924, 8925, 8926, 8927, 8928, 8929, 8936, 8938, 8939, 8940, 8941, 8949, 8950, 8951, 8955, 8972, 8983, 8992, 8998, 9000, 9005, 9490, 9492, 9493, 9634, 9745, 9747, 9750, 9752, 9754, 9756, 9758, 9821, 9823, 9827, 9829, 9830, 9833, 9834, 9835, 9839, 9840, 9841, 9845, 9846, 9849, 9850, 9852, 9853, 9856, 9857, 9858, 9862, 9863, 9866, 9867, 9875, 9876, 9880, 9881, 9884, 9885, 9888, 9889, 9892, 9894, 9896, 9898, 9901, 9904, 9908, 9910, 9912, 16689, 16810, 16811, 16812, 16813, 16857, 16914, 17329, 17401, 17402, 18657, 18658, 20484, 20719, 20739, 20742, 20747, 20748, 21849, 21850, 22568, 22570, 22812, 22827, 22828, 22829, 22842, 24248, 25297, 25298, 25299, 26978, 26979, 26980, 26981, 26982, 26983, 26984, 26985, 26986, 26987, 26988, 26989, 26990, 26991, 26992, 26994, 26995, 26996, 26997, 26998, 27000, 27001, 27002, 27003, 27004, 27005, 27006, 27008, 27009, 27012, 29166, 31018, 31709, 33357, 33745, 33763, 33786, 48377, 48378, 48440, 48441, 48442, 48443, 48446, 48447, 48450, 48451, 48459, 48461, 48462, 48463, 48464, 48465, 48467, 48469, 48470, 48477, 48479, 48480, 48559, 48560, 48561, 48562, 48567, 48568, 48569, 48570, 48571, 48572, 48573, 48574, 48575, 48576, 48577, 48578, 48579, 49799, 49800, 49802, 49803, 50212, 50213, 50464, 50763, 50764, 50765, 50766, 50767, 50768, 50769, 52610, 53307, 53308, 53312, 62078, 62600 };
int spellHunter[]      = { 2973, 136, 781, 883, 982, 1002, 1130, 1462, 1494, 1495, 1499, 1510, 1513, 1515, 1543, 1978, 2641, 2643, 2974, 3034, 3043, 3044, 3045, 3111, 3661, 3662, 5116, 5118, 5384, 6197, 6991, 13159, 13161, 13163, 13165, 13542, 13543, 13544, 13549, 13550, 13551, 13552, 13553, 13554, 13555, 13795, 13809, 13813, 14260, 14261, 14262, 14263, 14264, 14265, 14266, 14269, 14270, 14271, 14281, 14282, 14283, 14284, 14285, 14286, 14287, 14288, 14289, 14290, 14294, 14295, 14302, 14303, 14304, 14305, 14310, 14311, 14316, 14317, 14318, 14319, 14320, 14321, 14322, 14323, 14324, 14325, 14326, 14327, 19263, 19801, 19878, 19879, 19880, 19882, 19883, 19884, 19885, 20043, 20190, 20736, 25294, 25295, 25296, 27014, 27016, 27019, 27021, 27022, 27023, 27025, 27044, 27045, 27046, 34026, 34074, 34120, 34477, 34600, 36916, 48989, 48990, 48995, 48996, 49000, 49001, 49044, 49045, 49047, 49048, 49051, 49052, 49055, 49056, 49066, 49067, 49071, 53271, 53338, 53339, 53351, 56641, 58431, 58434, 60192, 61005, 61006, 61846, 61847, 62757 };
int spellRogue[]       = { 2098, 1752, 53, 408, 703, 921, 1725, 1757, 1758, 1759, 1760, 1766, 1776, 1784, 1804, 1833, 1842, 1856, 1857, 1860, 1943, 1966, 2070, 2094, 2589, 2590, 2591, 2836, 2983, 3127, 5171, 5277, 5938, 6760, 6761, 6762, 6768, 6770, 6774, 8621, 8623, 8624, 8631, 8632, 8633, 8637, 8639, 8640, 8643, 8647, 8676, 8696, 8721, 8724, 8725, 11267, 11268, 11269, 11273, 11274, 11275, 11279, 11280, 11281, 11289, 11290, 11293, 11294, 11297, 11299, 11300, 11303, 11305, 25300, 25302, 26669, 26679, 26839, 26861, 26862, 26863, 26865, 26867, 26884, 26889, 27441, 27448, 31016, 31224, 32645, 32684, 48637, 48638, 48656, 48657, 48658, 48659, 48667, 48668, 48671, 48672, 48673, 48674, 48675, 48676, 48689, 48690, 48691, 51722, 51723, 51724, 57934, 57992, 57993 };
int spellDeathKnight[] = { 48266, 45902, 45477, 47541, 50977, 49576, 45462, 3714, 42650, 43265, 45463, 45524, 45529, 46584, 47476, 47528, 47568, 48263, 48265, 48707, 48721, 48743, 48792, 49020, 49892, 49893, 49894, 49895, 49896, 49903, 49904, 49909, 49917, 49918, 49919, 49920, 49921, 49923, 49924, 49926, 49927, 49928, 49929, 49930, 49936, 49937, 49938, 49939, 49940, 49941, 49998, 49999, 50842, 51423, 51424, 51425, 53323, 53331, 53342, 53344, 54446, 54447, 56222, 56815, 57330, 57623, 61999, 62158, 70164 };

int spellPriest[208][2] = {{1243,1},{2050,1},{585,1},{2052,4},{589,4},{591,6},{17,6},{586,8},{139,8},{2006,10},{2053,10},{8092,10},{594,10},{592,12},{588,12},{1244,12},{598,14},{6074,14},{8122,14},{528,14},{2054,16},{8102,16},{600,18},{527,18},{970,18},{7128,20},{9484,20},{14914,20},{2061,20},{15237,20},{6075,20},{2944,20},{453,20},{6346,20},{2055,22},{2010,22},{984,22},{2096,22},{8103,22},{1245,24},{3747,24},{15262,24},{8129,24},{9472,26},{6076,26},{992,26},{6063,28},{15430,28},{8124,28},{19276,28},{8104,28},{6065,30},{602,30},{14752,30},{596,30},{15263,30},{1004,30},{976,30},{605,30},{552,32},{9473,32},{6077,32},{6064,34},{10880,34},{8105,34},{2767,34},{1706,34},{6066,36},{988,36},{2791,36},{15264,36},{15431,36},{19277,36},{9474,38},{6060,38},{6078,38},{1006,40},{14818,40},{9485,40},{996,40},{2060,40},{8106,40},{10898,42},{15265,42},{10888,42},{10957,42},{10892,42},{10915,44},{27799,44},{10927,44},{10909,44},{19278,44},{10963,46},{10881,46},{10933,46},{10945,46},{10899,48},{10937,48},{21562,48},{15266,48},{10951,50},{14819,50},{10960,50},{10916,50},{10928,50},{10893,50},{10964,52},{27800,52},{19279,52},{10946,52},{10900,54},{15267,54},{10934,54},{10917,56},{10929,56},{10890,56},{10958,56},{27683,56},{10965,58},{20770,58},{10947,58},{10894,58},{10952,60},{27841,60},{10901,60},{10938,60},{21564,60},{27681,60},{10955,60},{10961,60},{25316,60},{25314,60},{15261,60},{27801,60},{25315,60},{19280,60},{25233,61},{25363,61},{32379,62},{25210,63},{25372,63},{32546,64},{25217,65},{25221,65},{25367,65},{25384,66},{34433,66},{25235,67},{25308,68},{25213,68},{25435,68},{33076,68},{25331,68},{25433,68},{25467,68},{25431,69},{25364,69},{25375,69},{25312,70},{25218,70},{25389,70},{25392,70},{32999,70},{25222,70},{39374,70},{32996,70},{32375,70},{25368,70},{48040,71},{48119,72},{48134,72},{48062,73},{48070,73},{48299,73},{48112,74},{48122,74},{48126,74},{48065,75},{48077,75},{48067,75},{48045,75},{48157,75},{48124,75},{48072,76},{48169,76},{48168,77},{48170,77},{48120,78},{48063,78},{48135,78},{48171,78},{48071,79},{48113,79},{48123,79},{48300,79},{48127,79},{48073,80},{48161,80},{48066,80},{48162,80},{48074,80},{48078,80},{48068,80},{53023,80},{48158,80},{48125,80},{64843,80},{64901,80}};
int talentPriest[34][3] = {{53005,70,47540},{53006,75,53005},{53007,80,53006},{19238,26,19236},{19240,34,19238},{19241,42,19240},{19242,50,19241},{19243,58,19242},{25437,66,19243},{48172,73,25437},{48173,80,48172},{27870,50,724},{27871,60,27870},{28275,70,27871},{48086,75,28275},{48087,80,48086},{34863,56,34861},{34864,60,34863},{34865,65,34864},{34866,70,34865},{48088,75,34866},{48089,80,48088},{17311,28,15407},{17312,36,17311},{17313,44,17312},{17314,52,17313},{18807,60,17314},{25387,68,18807},{48155,74,25387},{48156,80,48155},{34916,60,34914},{34917,70,34916},{48159,75,34917},{48160,80,48159}};
int spellPaladin[160][2] = {{21084,1},{635,1},{465,1},{19740,4},{20271,4},{498,6},{639,6},{853,8},{1152,8},{1022,10},{633,10},{10290,10},{53408,12},{19834,12},{7328,12},{19742,14},{31789,14},{647,14},{25780,16},{62124,16},{7294,16},{1044,18},{20217,20},{643,20},{879,20},{19750,20},{5502,20},{26573,20},{19835,22},{20164,22},{1026,22},{19746,22},{5599,24},{5588,24},{19850,24},{10322,24},{10326,24},{1038,26},{10298,26},{19939,26},{19876,28},{5614,28},{53407,28},{2800,30},{19752,30},{10291,30},{20165,30},{1042,30},{20116,30},{19888,32},{19836,32},{642,34},{19852,34},{19940,34},{10299,36},{19891,36},{5615,36},{10324,36},{10278,38},{20186,38},{20166,38},{3472,38},{5589,40},{19895,40},{1032,40},{20922,40},{19837,42},{19941,42},{4987,42},{19853,44},{19897,44},{10312,44},{24275,44},{6940,46},{10300,46},{10328,46},{19899,48},{20772,48},{2812,50},{10310,50},{10292,50},{19942,50},{20923,50},{19896,52},{25782,52},{19838,52},{10313,52},{24274,52},{10308,54},{19854,54},{25894,54},{10329,54},{10301,56},{19898,56},{19943,58},{25290,60},{25918,60},{19900,60},{10318,60},{25291,60},{25916,60},{25898,60},{10293,60},{10314,60},{24239,60},{20773,60},{25292,60},{20924,60},{27135,62},{32223,62},{27151,63},{27142,65},{27143,65},{27150,66},{27137,66},{27152,68},{27138,68},{27180,68},{27139,69},{27154,69},{27153,70},{31884,70},{27140,70},{27141,70},{27149,70},{27136,70},{27173,70},{48935,71},{48937,71},{54428,71},{48816,72},{48949,72},{48931,73},{48933,73},{48800,73},{48941,74},{48784,74},{48805,74},{53600,75},{48781,75},{48818,75},{54043,76},{48943,76},{48936,77},{48938,77},{48945,77},{48947,78},{48817,78},{48788,78},{48932,79},{48934,79},{48942,79},{48801,79},{48785,79},{48950,79},{48806,80},{53601,80},{61411,80},{48782,80},{48819,80}};
int talentPaladin[16][3] = {{20929,48,20473},{20930,56,20929},{27174,64,20930},{33072,70,27174},{48824,75,33072},{48825,80,48824},{25899,60,20911},{20927,50,20925},{20928,60,20927},{27179,70,20928},{48951,75,27179},{48952,80,48951},{32699,60,31935},{32700,70,32699},{48826,75,32700},{48827,80,48826}};
int spellWarrior[125][2] = {{78,1},{2457,1},{6673,1},{100,4},{772,4},{6343,6},{34428,6},{284,8},{1715,8},{71,10},{355,10},{2687,10},{6546,10},{7386,10},{72,12},{5242,12},{7384,12},{1160,14},{6572,14},{285,16},{694,16},{2565,16},{676,18},{8198,18},{845,20},{6547,20},{12678,20},{20230,20},{5246,22},{6192,22},{1608,24},{5308,24},{6190,24},{6574,24},{1161,26},{6178,26},{871,28},{8204,28},{1464,30},{2458,30},{6548,30},{7369,30},{20252,30},{11549,32},{11564,32},{18499,32},{20658,32},{7379,34},{11554,34},{1680,36},{6552,38},{8205,38},{8820,38},{11565,40},{11572,40},{11608,40},{20660,40},{23922,40},{11550,42},{11555,44},{11600,44},{11578,46},{11604,46},{11566,48},{11580,48},{20661,48},{23923,48},{1719,50},{11573,50},{11609,50},{11551,52},{11556,54},{11601,54},{11605,54},{23924,54},{11567,56},{20662,56},{11581,58},{11574,60},{20569,60},{23925,60},{25286,60},{25288,60},{25289,60},{25241,61},{25202,62},{25269,63},{23920,64},{25234,65},{25258,66},{29707,66},{25264,67},{469,68},{25208,68},{25231,68},{2048,69},{25242,69},{3411,70},{25203,70},{25236,70},{30324,70},{30356,70},{30357,70},{46845,71},{64382,71},{47449,72},{47519,72},{47470,73},{47501,73},{47439,74},{47474,74},{47487,75},{55694,75},{47450,76},{47465,76},{47520,77},{47436,78},{47502,78},{47437,79},{47475,79},{47440,80},{47471,80},{47488,80},{57755,80},{57823,80}};
int talentWarrior[11][3] = {{21551,48,12294},{21552,54,21551},{21553,60,21552},{25248,66,21553},{30330,70,25248},{47485,75,30330},{47486,80,47485},{30016,60,20243},{30022,70,30016},{47497,75,30022},{47498,80,47497}};
int spellMage[223][2] = {{133,1},{168,1},{1459,1},{116,4},{5504,4},{143,6},{587,6},{2136,6},{118,8},{205,8},{5143,8},{122,10},{5505,10},{7300,10},{130,12},{145,12},{597,12},{604,12},{837,14},{1449,14},{1460,14},{2137,14},{2120,16},{5144,16},{475,18},{1008,18},{3140,18},{10,20},{543,20},{1463,20},{1953,20},{5506,20},{7301,20},{7322,20},{12051,20},{12824,20},{990,22},{2138,22},{2948,22},{6143,22},{8437,22},{2121,24},{2139,24},{5145,24},{8400,24},{8450,24},{120,26},{865,26},{8406,26},{759,28},{1461,28},{6141,28},{8444,28},{8494,28},{6127,30},{7302,30},{8401,30},{8412,30},{8438,30},{8455,30},{8457,30},{45438,30},{6129,32},{8407,32},{8416,32},{8422,32},{8461,32},{6117,34},{8445,34},{8492,34},{8402,36},{8427,36},{8451,36},{8495,36},{3552,38},{8408,38},{8413,38},{8439,38},{6131,40},{7320,40},{8417,40},{8423,40},{8446,40},{8458,40},{10138,40},{12825,40},{8462,42},{10144,42},{10148,42},{10156,42},{10159,42},{10169,42},{10179,44},{10185,44},{10191,44},{10197,46},{10201,46},{10205,46},{22782,46},{10053,48},{10149,48},{10173,48},{10211,48},{10215,48},{10139,50},{10160,50},{10180,50},{10219,50},{10223,50},{10145,52},{10177,52},{10186,52},{10192,52},{10206,52},{10150,54},{10170,54},{10199,54},{10202,54},{10230,54},{10157,56},{10181,56},{10212,56},{10216,56},{23028,56},{10054,58},{10161,58},{10207,58},{22783,58},{10140,60},{10151,60},{10174,60},{10187,60},{10193,60},{10220,60},{10225,60},{12826,60},{25304,60},{25306,60},{25345,60},{28609,60},{28612,60},{27078,61},{27080,62},{30482,62},{27071,63},{27075,63},{27130,63},{27086,64},{30451,64},{27073,65},{27087,65},{37420,65},{27070,66},{30455,66},{27088,67},{33944,67},{66,68},{27085,68},{27101,68},{27131,68},{27072,69},{27124,69},{27125,69},{27128,69},{33946,69},{38699,69},{27074,70},{27079,70},{27082,70},{27090,70},{27126,70},{27127,70},{30449,70},{32796,70},{33717,70},{38692,70},{38697,70},{38704,70},{43987,70},{42894,71},{43023,71},{43045,71},{42913,72},{42925,72},{42930,72},{42858,73},{43019,73},{42832,74},{42872,74},{42939,74},{42841,75},{42843,75},{42917,75},{42955,75},{44614,75},{42896,76},{42920,76},{43015,76},{42985,77},{43017,77},{42833,78},{42859,78},{42914,78},{43010,78},{42842,79},{42846,79},{42926,79},{42931,79},{43008,79},{43012,79},{43020,79},{43024,79},{43046,79},{42873,80},{42897,80},{42921,80},{42940,80},{42956,80},{42995,80},{43002,80},{47610,80},{55342,80},{58659,80}};
int talentMage[35][3] = {{44780,70,44425},{44781,80,44780},{12505,24,11366},{12522,30,12505},{12523,36,12522},{12524,42,12523},{12525,48,12524},{12526,54,12525},{18809,60,12526},{27132,66,18809},{33938,70,27132},{42890,73,33938},{42891,77,42890},{13018,36,11113},{13019,44,13018},{13020,52,13019},{13021,60,13020},{27133,65,13021},{33933,70,27133},{42944,75,33933},{42945,80,42944},{33041,56,31661},{33042,64,33041},{33043,70,33042},{42949,75,33043},{42950,80,42949},{55359,70,44457},{55360,80,55359},{13031,46,11426},{13032,52,13031},{13033,58,13032},{27134,64,13033},{33405,70,27134},{43038,75,33405},{43039,80,43038}};
int spellWarlock[211][2] = {{348,1},{686,1},{687,1},{688,1},{172,4},{702,4},{695,6},{1454,6},{980,8},{5782,8},{696,10},{697,10},{707,10},{1120,10},{6201,10},{705,12},{755,12},{1108,12},{689,14},{6222,14},{1455,16},{5697,16},{693,18},{1014,18},{5676,18},{698,20},{706,20},{712,20},{1088,20},{1094,20},{3698,20},{5740,20},{126,22},{699,22},{6202,22},{6205,22},{5138,24},{5500,24},{6223,24},{8288,24},{132,26},{1456,26},{1714,26},{17919,26},{710,28},{1106,28},{3699,28},{6217,28},{6366,28},{691,30},{709,30},{1086,30},{1098,30},{1949,30},{2941,30},{20752,30},{1490,32},{6213,32},{6229,32},{7646,32},{5699,34},{6219,34},{7648,34},{17920,34},{2362,36},{3700,36},{7641,36},{11687,36},{17951,36},{7651,38},{8289,38},{11711,38},{5484,40},{11665,40},{11733,40},{20755,40},{6789,42},{11683,42},{11707,42},{11739,42},{17921,42},{11659,44},{11671,44},{11693,44},{11725,44},{11677,46},{11688,46},{11699,46},{11721,46},{11729,46},{17952,46},{6353,48},{11712,48},{17727,48},{18647,48},{11667,50},{11719,50},{11734,50},{17922,50},{17925,50},{20756,50},{11660,52},{11675,52},{11694,52},{11708,52},{11740,52},{11672,54},{11684,54},{11700,54},{17928,54},{6215,56},{11689,56},{17924,56},{17953,56},{11678,58},{11713,58},{11726,58},{11730,58},{17923,58},{17926,58},{603,60},{11661,60},{11668,60},{11695,60},{11722,60},{11735,60},{17728,60},{20757,60},{25307,60},{25309,60},{25311,60},{28610,60},{27224,61},{27219,62},{28176,62},{27211,64},{29722,64},{27210,65},{27216,65},{27250,66},{28172,66},{29858,66},{27217,67},{27218,67},{27259,67},{27213,68},{27222,68},{27223,68},{27230,68},{29893,68},{27209,69},{27212,69},{27215,69},{27220,69},{27228,69},{28189,69},{30909,69},{27238,70},{27243,70},{27260,70},{30459,70},{30545,70},{30910,70},{32231,70},{47812,71},{50511,71},{47819,72},{47886,72},{47890,72},{61191,72},{47859,73},{47863,73},{47871,73},{47808,74},{47814,74},{47837,74},{47892,74},{60219,74},{47810,75},{47824,75},{47835,75},{47897,75},{47793,76},{47856,76},{47884,76},{47813,77},{47855,77},{47823,78},{47857,78},{47860,78},{47865,78},{47888,78},{47891,78},{47809,79},{47815,79},{47820,79},{47864,79},{47878,79},{47893,79},{47811,80},{47825,80},{47836,80},{47838,80},{47867,80},{47889,80},{48018,80},{48020,80},{57946,80},{58887,80},{60220,80},{61290,80}};
int talentWarlock[27][3] = {{18937,50,18220},{18938,60,18937},{27265,70,18938},{59092,80,27265},{30404,60,30108},{30405,70,30404},{47841,75,30405},{47843,80,47841},{59161,70,48181},{59163,75,59161},{59164,80,59163},{18867,24,17877},{18868,32,18867},{18869,40,18868},{18870,48,18869},{18871,56,18870},{27263,63,18871},{30546,70,27263},{47826,75,30546},{47827,80,47826},{30413,60,30283},{30414,70,30413},{47846,75,30414},{47847,80,47846},{59170,70,50796},{59171,75,59170},{59172,80,59171}};
int spellShaman[266][2] = {{331,1},{403,1},{8017,1},{8042,4},{8071,4},{332,6},{2484,6},{324,8},{529,8},{5730,8},{8018,8},{8044,8},{3599,10},{8024,10},{8050,10},{8075,10},{370,12},{547,12},{1535,12},{2008,12},{548,14},{8045,14},{8154,14},{325,16},{526,16},{2645,16},{8019,16},{57994,16},{913,18},{6390,18},{8027,18},{8052,18},{8143,18},{915,20},{5394,20},{6363,20},{8004,20},{8033,20},{8056,20},{52127,20},{131,22},{8498,22},{905,24},{939,24},{8046,24},{8155,24},{8160,24},{8181,24},{10399,24},{20609,24},{943,26},{5675,26},{6196,26},{8030,26},{8190,26},{546,28},{6391,28},{8008,28},{8038,28},{8053,28},{8184,28},{8227,28},{52129,28},{556,30},{6364,30},{6375,30},{8177,30},{8232,30},{10595,30},{20608,30},{36936,30},{51730,30},{66842,30},{421,32},{945,32},{959,32},{6041,32},{8012,32},{8499,32},{8512,32},{6495,34},{8058,34},{10406,34},{52131,34},{8010,36},{10412,36},{10495,36},{10585,36},{16339,36},{20610,36},{6392,38},{8161,38},{8170,38},{8249,38},{10391,38},{10456,38},{10478,38},{930,40},{1064,40},{6365,40},{6377,40},{8005,40},{8134,40},{8235,40},{10447,40},{51988,40},{66843,40},{52134,41},{10537,42},{11314,42},{10392,44},{10407,44},{10466,44},{10600,44},{10472,46},{10496,46},{10586,46},{10622,46},{16341,46},{2860,48},{10395,48},{10413,48},{10427,48},{10431,48},{10526,48},{16355,48},{20776,48},{52136,48},{10437,50},{10462,50},{10486,50},{15207,50},{51991,50},{66844,50},{10442,52},{10448,52},{10467,52},{11315,52},{10408,54},{10479,54},{10623,54},{52138,55},{10396,56},{10432,56},{10497,56},{10587,56},{10605,56},{15208,56},{16342,56},{10428,58},{10473,58},{10538,58},{16356,58},{16387,58},{10414,60},{10438,60},{10463,60},{10468,60},{10601,60},{16362,60},{20777,60},{25357,60},{25361,60},{29228,60},{51992,60},{25422,61},{25546,61},{24398,62},{25448,62},{25391,63},{25439,63},{25469,63},{25508,63},{3738,64},{25489,64},{25528,65},{25552,65},{25570,65},{2062,66},{25420,66},{25500,66},{25449,67},{25525,67},{25557,67},{25560,67},{2894,68},{25423,68},{25464,68},{25505,68},{25563,68},{25454,69},{25533,69},{25567,69},{25574,69},{25590,69},{33736,69},{2825,70},{25396,70},{25442,70},{25457,70},{25472,70},{25509,70},{25547,70},{51993,70},{58580,71},{58649,71},{58699,71},{58755,71},{58771,71},{58785,71},{58794,71},{58801,71},{49275,72},{49235,73},{49237,73},{58731,73},{58751,73},{49230,74},{49270,74},{55458,74},{49232,75},{49272,75},{49280,75},{51505,75},{57622,75},{58581,75},{58652,75},{58703,75},{58737,75},{58741,75},{58746,75},{61649,75},{57960,76},{58756,76},{58773,76},{58789,76},{58795,76},{58803,76},{49276,77},{49236,78},{58582,78},{58734,78},{58753,78},{49231,79},{49238,79},{49233,80},{49271,80},{49273,80},{49277,80},{49281,80},{51514,80},{51994,80},{55459,80},{58643,80},{58656,80},{58704,80},{58739,80},{58745,80},{58749,80},{58757,80},{58774,80},{58790,80},{58796,80},{58804,80},{60043,80},{61657,80}};
int talentShaman[13][3]= {{57720,60,30706},{57721,70,57720},{57722,80,57721},{59156,70,51490},{59158,75,59156},{59159,80,59158},{32593,60,974},{32594,70,32593},{49283,75,32594},{49284,80,49283},{61299,70,61295},{61300,75,61299},{61301,80,61300}};

int spellDruid[x][2] = {};
int talentDruid[24][3] = {{24974,30,5570},{24975,40,24974},{24976,50,24975},{24977,60,24976},{27013,70,24977},{48468,80,27013},{53223,60,50516},{53225,70,53223},{53226,75,53225},{61384,80,53226},{53199,70,48505},{53200,75,53199},{53201,80,53200},{33986,58,33878},{33987,68,33986},{48563,75,33987},{48564,80,48563},{33982,58,33876},{33983,68,33982},{48565,75,33983},{48566,80,48565},{53248,70,48438},{53249,75,53248},{53251,80,53249}};

int spellHunter[x][2] = {};
int talentHunter[26][3] = {{20900,28,19434},{20901,36,20900},{20902,44,20901},{20903,52,20902},{20904,60,20903},{27065,70,20904},{49049,75,27065},{49050,80,49049},{20909,42,19306},{20910,54,20909},{27067,66,20910},{48998,72,27067},{48999,78,48998},{24132,50,19386},{24133,60,24132},{27068,70,24133},{49011,75,27068},{49012,80,49011},{63668,57,3674},{63669,63,63668},{63670,69,63669},{63671,75,63670},{63672,80,63671},{60051,70,53301},{60052,75,60051},{60053,80,60052}};

int spellRogue[x][2] = {};
int talentRogue[9][3] = {{34411,50,1329},{34412,60,34411},{34413,70,34412},{48663,75,34413},{48666,80,48663},{17347,46,16511},{17348,58,17347},{26864,70,17348},{48660,80,26864}};

int spellDeathKnight[x][2] = {};
int talentDeathKnight[20][3] = {{55258,59,55050},{55259,64,55258},{55260,69,55259},{55261,74,55260},{55262,80,55261},{51416,60,49143},{51417,65,51416},{51418,70,51417},{51419,75,51418},{55268,80,51419},{51409,70,49184},{51410,75,51409},{51411,80,51410},{51325,60,49158},{51326,70,51325},{51327,75,51326},{51328,80,51327},{55265,67,55090},{55270,73,55265},{55271,79,55270}};

int mountSkill[5][3] = {{33388,20,true},{33391,40,true},{34090,60,true},{34091,70,false},{54197,77,false}};
int mountSpell[79][4] = {{458,33388,RACE_HUMAN,TEAM_ALLIANCE},{472,33388,RACE_HUMAN,TEAM_ALLIANCE},{6648,33388,RACE_HUMAN,TEAM_ALLIANCE},{23227,33391,RACE_HUMAN,TEAM_ALLIANCE},{23228,33391,RACE_HUMAN,TEAM_ALLIANCE},{23229,33391,RACE_HUMAN,TEAM_ALLIANCE},{8394,33388,RACE_NIGHTELF,TEAM_ALLIANCE},{10789,33388,RACE_NIGHTELF,TEAM_ALLIANCE},{10793,33388,RACE_NIGHTELF,TEAM_ALLIANCE},{66847,33388,RACE_NIGHTELF,TEAM_ALLIANCE},{23221,33391,RACE_NIGHTELF,TEAM_ALLIANCE},{23219,33391,RACE_NIGHTELF,TEAM_ALLIANCE},{23338,33391,RACE_NIGHTELF,TEAM_ALLIANCE},{10873,33388,RACE_GNOME,TEAM_ALLIANCE},{10969,33388,RACE_GNOME,TEAM_ALLIANCE},{17453,33388,RACE_GNOME,TEAM_ALLIANCE},{17454,33388,RACE_GNOME,TEAM_ALLIANCE},{23222,33391,RACE_GNOME,TEAM_ALLIANCE},{23223,33391,RACE_GNOME,TEAM_ALLIANCE},{23225,33391,RACE_GNOME,TEAM_ALLIANCE},{6777,33388,RACE_DWARF,TEAM_ALLIANCE},{6898,33388,RACE_DWARF,TEAM_ALLIANCE},{6899,33388,RACE_DWARF,TEAM_ALLIANCE},{23238,33391,RACE_DWARF,TEAM_ALLIANCE},{23239,33391,RACE_DWARF,TEAM_ALLIANCE},{23240,33391,RACE_DWARF,TEAM_ALLIANCE},{34406,33388,RACE_DRAENEI,TEAM_ALLIANCE},{35710,33388,RACE_DRAENEI,TEAM_ALLIANCE},{35711,33388,RACE_DRAENEI,TEAM_ALLIANCE},{35712,33391,RACE_DRAENEI,TEAM_ALLIANCE},{35713,33391,RACE_DRAENEI,TEAM_ALLIANCE},{35714,33391,RACE_DRAENEI,TEAM_ALLIANCE},{32239,34090,0,TEAM_ALLIANCE},{32240,34090,0,TEAM_ALLIANCE},{32235,34090,0,TEAM_ALLIANCE},{32242,34091,0,TEAM_ALLIANCE},{32289,34091,0,TEAM_ALLIANCE},{32290,34091,0,TEAM_ALLIANCE},{32292,34091,0,TEAM_ALLIANCE},{580,33388,RACE_ORC,TEAM_HORDE},{6653,33388,RACE_ORC,TEAM_HORDE},{6654,33388,RACE_ORC,TEAM_HORDE},{64658,33388,RACE_ORC,TEAM_HORDE},{23250,33391,RACE_ORC,TEAM_HORDE},{23251,33391,RACE_ORC,TEAM_HORDE},{23252,33391,RACE_ORC,TEAM_HORDE},{8395,33388,RACE_TROLL,TEAM_HORDE},{10796,33388,RACE_TROLL,TEAM_HORDE},{10799,33388,RACE_TROLL,TEAM_HORDE},{23241,33391,RACE_TROLL,TEAM_HORDE},{23242,33391,RACE_TROLL,TEAM_HORDE},{23243,33391,RACE_TROLL,TEAM_HORDE},{17462,33388,RACE_UNDEAD_PLAYER,TEAM_HORDE},{17463,33388,RACE_UNDEAD_PLAYER,TEAM_HORDE},{17464,33388,RACE_UNDEAD_PLAYER,TEAM_HORDE},{64977,33388,RACE_UNDEAD_PLAYER,TEAM_HORDE},{17465,33391,RACE_UNDEAD_PLAYER,TEAM_HORDE},{23246,33391,RACE_UNDEAD_PLAYER,TEAM_HORDE},{66846,33391,RACE_UNDEAD_PLAYER,TEAM_HORDE},{18989,33388,RACE_TAUREN,TEAM_HORDE},{18990,33388,RACE_TAUREN,TEAM_HORDE},{64657,33388,RACE_TAUREN,TEAM_HORDE},{23247,33391,RACE_TAUREN,TEAM_HORDE},{23248,33391,RACE_TAUREN,TEAM_HORDE},{23249,33391,RACE_TAUREN,TEAM_HORDE},{34795,33388,RACE_BLOODELF,TEAM_HORDE},{35018,33388,RACE_BLOODELF,TEAM_HORDE},{35020,33388,RACE_BLOODELF,TEAM_HORDE},{35022,33388,RACE_BLOODELF,TEAM_HORDE},{33660,33391,RACE_BLOODELF,TEAM_HORDE},{35025,33391,RACE_BLOODELF,TEAM_HORDE},{35027,33391,RACE_BLOODELF,TEAM_HORDE},{32243,34090,0,TEAM_HORDE},{32244,34090,0,TEAM_HORDE},{32245,34090,0,TEAM_HORDE},{32246,34091,0,TEAM_HORDE},{32295,34091,0,TEAM_HORDE},{32296,34091,0,TEAM_HORDE},{32297,34091,0,TEAM_HORDE}};

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
