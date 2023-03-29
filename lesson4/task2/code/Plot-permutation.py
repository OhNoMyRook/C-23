import matplotlib.pyplot as plt

plt.title("Перестановки от количества")
x = [100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2300, 2400, 2500, 2600, 2700, 2800, 2900, 3000, 3100, 3200, 3300, 3400, 3500, 3600, 3700, 3800, 3900, 4000, 4100, 4200, 4300, 4400, 4500, 4600, 4700, 4800, 4900, 5000, 5100, 5200, 5300, 5400, 5500, 5600, 5700, 5800, 5900, 6000, 6100, 6200, 6300, 6400, 6500, 6600, 6700, 6800, 6900, 7000, 7100, 7200, 7300, 7400, 7500, 7600, 7700, 7800, 7900, 8000, 8100, 8200, 8300, 8400, 8500, 8600, 8700, 8800, 8900, 9000, 9100, 9200, 9300, 9400, 9500, 9600, 9700, 9800, 9900, 10000]
y = [754, 2047, 3996, 8441, 9844, 14435, 17845, 28662, 31182, 34380, 41169, 60225, 57742, 66674, 76202, 120177, 96310, 120429, 116446, 168497, 142677, 179830, 164357, 229693, 229034, 245323, 234739, 323361, 255349, 306787, 300662, 421375, 362330, 398288, 368220, 491082, 436141, 518956, 448261, 669856, 620313, 622329, 557388, 742933, 642242, 685232, 668567, 988154, 818304, 902516, 805629, 1033972, 894441, 1004422, 898688, 1277585, 1116978, 1147479, 1130131, 1298845, 1111042, 1311328, 1239369, 1677545, 1423299, 1516256, 1402315, 1807519, 1544728, 1715886, 1510736, 2162052, 1915222, 1911941, 1752881, 2256056, 1942485, 2073095, 1853928, 2560096, 2161580, 2440850, 2103968, 2642551, 2274404, 2494705, 2243747, 2928579, 2736580, 2775787, 2761101, 3133490, 2638562, 2996573, 2738982, 4004209, 3078131, 3391865, 3013365, 3811603]
plt.xlabel('Amount')
plt.ylabel('Permutation')
plt.scatter(x,y)
plt.savefig('Permutation-Amount.png')
plt.show()