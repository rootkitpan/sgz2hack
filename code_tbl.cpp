﻿#include <iostream>
#include "code_tbl.h"

using namespace std;

CODE_ITEM2 CodeTbl2[] = {
	{ 0x88, 0xA2, L'阿' },
	{ 0x88, 0xA7, L'逢' },
	{ 0x88, 0xC0, L'安' },
	{ 0x88, 0xC9, L'伊' },
	{ 0x88, 0xD0, L'威' },
	{ 0x88, 0xD9, L'異' },
	{ 0x88, 0xDB, L'維' },
	{ 0x88, 0xF2, L'允' },
	{ 0x88, 0xFB, L'胤' },

	{ 0x89, 0x48, L'羽' },
	{ 0x89, 0x5F, L'雲' },
	{ 0x89, 0x62, L'叡' },
	{ 0x89, 0x68, L'栄' },
	{ 0x89, 0x70, L'英' },
	{ 0x89, 0x71, L'衛' },
	{ 0x89, 0x72, L'可' },
	{ 0x89, 0x76, L'益' },
	{ 0x89, 0x7A, L'越' },
	{ 0x89, 0x84, L'延' },
	{ 0x89, 0x93, L'遠' },
	{ 0x89, 0x9E, L'応' },
	{ 0x89, 0xA1, L'横' },
	{ 0x89, 0xA4, L'王' },
	{ 0x89, 0xA9, L'黄' },
	{ 0x89, 0xB6, L'恩' },
	{ 0x89, 0xB7, L'温' },
	{ 0x89, 0xBB, L'化' },
	{ 0x89, 0xC2, L'可' },
	{ 0x89, 0xC3, L'嘉' },
	{ 0x89, 0xC4, L'夏' },
	{ 0x89, 0xD8, L'華' },
	{ 0x89, 0xEF, L'会' },
	{ 0x89, 0xF8, L'恢' },
	{ 0x89, 0xF9, L'懐' },

	{ 0x8A, 0x4D, L'凱' },
	{ 0x8A, 0x57, L'蓋' },
	{ 0x8A, 0x6C, L'獲' },
	{ 0x8A, 0x73, L'郭' },
	{ 0x8A, 0x79, L'楽' },
	{ 0x8A, 0x8B, L'葛' },
	{ 0x8A, 0xA3, L'乾' },
	{ 0x8A, 0xB2, L'幹' },
	{ 0x8A, 0xBA, L'桓' },
	{ 0x8A, 0xC2, L'環' },
	{ 0x8A, 0xC3, L'甘' },
	{ 0x8A, 0xC8, L'簡' },
	{ 0x8A, 0xCF, L'観' },
	{ 0x8A, 0xD6, L'関' },
	{ 0x8A, 0xD8, L'韓' },
	{ 0x8A, 0xDF, L'玩' },
	{ 0x8A, 0xE7, L'顔' },
	{ 0x8A, 0xF0, L'嬉' },

	{ 0x8B, 0x49, L'紀' },
	{ 0x8B, 0x56, L'儀' },
	{ 0x8B, 0x58, L'宜' },
	{ 0x8B, 0x60, L'義' },
	{ 0x8B, 0x75, L'丘' },
	{ 0x8B, 0x78, L'休' },
	{ 0x8B, 0x7B, L'宮' },
	{ 0x8B, 0x8D, L'牛' },
	{ 0x8B, 0x93, L'挙' },
	{ 0x8B, 0x94, L'渠' },
	{ 0x8B, 0x96, L'許' },
	{ 0x8B, 0xA7, L'匡' },
	{ 0x8B, 0xB8, L'矯' },
	{ 0x8B, 0xBB, L'興' },
	{ 0x8B, 0xD4, L'欽' },
	{ 0x8B, 0xD6, L'禁' },
	{ 0x8B, 0xE0, L'金' },
	{ 0x8B, 0xE2, L'銀' },
	{ 0x8B, 0xF1, L'虞' },

	{ 0x8C, 0x4D, L'勲' },
	{ 0x8C, 0x51, L'群' },
	{ 0x8C, 0x5D, L'珪' },
	{ 0x8C, 0x62, L'恵' },
	{ 0x8C, 0x74, L'荊' },
	{ 0x8C, 0x8B, L'結' },
	{ 0x8C, 0x90, L'倹' },
	{ 0x8C, 0x98, L'堅' },
	{ 0x8C, 0x9A, L'建' },
	{ 0x8C, 0x9B, L'憲' },
	{ 0x8C, 0xA0, L'権' },
	{ 0x8C, 0xAA, L'謙' },
	{ 0x8C, 0xAB, L'賢' },
	{ 0x8C, 0xB5, L'厳' },
	{ 0x8C, 0xBA, L'玄' },
	{ 0x8C, 0xD3, L'胡' },
	{ 0x8C, 0xD5, L'虎' },
	{ 0x8C, 0xDA, L'顧' },
	{ 0x8C, 0xE0, L'呉' },
	{ 0x8C, 0xF0, L'交' },
	{ 0x8C, 0xF2, L'侯' },
	{ 0x8C, 0xF6, L'公' },

	{ 0x8D, 0x45, L'孔' },
	{ 0x8D, 0x4C, L'広' },
	{ 0x8D, 0x56, L'昂' },
	{ 0x8D, 0x57, L'晃' },
	{ 0x8D, 0x5E, L'洪' },
	{ 0x8D, 0x5F, L'浩' },
	{ 0x8D, 0x68, L'紘' },
	{ 0x8D, 0x74, L'衡' },
	{ 0x8D, 0x82, L'高' },
	{ 0x8D, 0x84, L'剛' },
	{ 0x8D, 0x91, L'国' },
	{ 0x8D, 0xB9, L'沙' },
	{ 0x8D, 0xCF, L'済' },
	{ 0x8D, 0xF4, L'策' },
	{ 0x8D, 0xF5, L'索' },

	{ 0x8E, 0x69, L'司' },
	{ 0x8E, 0x6A, L'史' },
	{ 0x8E, 0x6D, L'士' },
	{ 0x8E, 0x74, L'師' },
	{ 0x8E, 0x75, L'志' },
	{ 0x8E, 0x76, L'思' },
	{ 0x8E, 0x8D, L'詩' },
	{ 0x8E, 0x91, L'資' },
	{ 0x8E, 0x9C, L'慈' },
	{ 0x8E, 0xA1, L'治' },
	{ 0x8E, 0xAE, L'式' },
	{ 0x8E, 0xB1, L'竺' },
	{ 0x8E, 0xC5, L'芝' },
	{ 0x8E, 0xD3, L'謝' },
	{ 0x8E, 0xE9, L'朱' },
	{ 0x8E, 0xF2, L'儒' },
	{ 0x8E, 0xF6, L'授' },
	{ 0x8E, 0xFC, L'周' },

	{ 0x8F, 0x41, L'就' },
	{ 0x8F, 0x43, L'修' },
	{ 0x8F, 0x48, L'秋' },
	{ 0x8F, 0x4A, L'繍' },
	{ 0x8F, 0x50, L'襲' },
	{ 0x8F, 0x58, L'醜' },
	{ 0x8F, 0x5F, L'柔' },
	{ 0x8F, 0x6C, L'粛' },
	{ 0x8F, 0x70, L'術' },
	{ 0x8F, 0x73, L'峻' },
	{ 0x8F, 0x7A, L'循' },
	{ 0x8F, 0x7E, L'淳' },
	{ 0x8F, 0x83, L'純' },
	{ 0x8F, 0x87, L'順' },
	{ 0x8F, 0x8E, L'庶' },
	{ 0x8F, 0x94, L'諸' },
	{ 0x8F, 0x99, L'徐' },
	{ 0x8F, 0xA4, L'商' },
	{ 0x8F, 0xAE, L'尚' },
	{ 0x8F, 0xB2, L'彰' },
	{ 0x8F, 0xB3, L'承' },
	{ 0x8F, 0xBA, L'昭' },
	{ 0x8F, 0xBC, L'松' },
	{ 0x8F, 0xC5, L'焦' },
	{ 0x8F, 0xD0, L'紹' },
	{ 0x8F, 0xD3, L'蒋' },
	{ 0x8F, 0xDF, L'鍾' },
	{ 0x8F, 0xED, L'常' },

	{ 0x90, 0x41, L'植' },
	{ 0x90, 0x47, L'触' },
	{ 0x90, 0x4D, L'信' },
	{ 0x90, 0x52, L'審' },
	{ 0x90, 0x5E, L'真' },
	{ 0x90, 0x68, L'辛' },
	{ 0x90, 0x69, L'進' },
	{ 0x90, 0x6B, L'震' },
	{ 0x90, 0x6D, L'仁' },
	{ 0x90, 0x7D, L'図' },
	{ 0x90, 0x8B, L'遂' },
	{ 0x90, 0x93, L'嵩' },
	{ 0x90, 0xAC, L'成' },
	{ 0x90, 0xB3, L'正' },
	{ 0x90, 0xB7, L'盛' },
	{ 0x90, 0xC2, L'青' },
	{ 0x90, 0xD0, L'籍' },
	{ 0x90, 0xD1, L'績' },
	{ 0x90, 0xF9, L'旋' },

	{ 0x91, 0x49, L'選' },
	{ 0x91, 0x52, L'然' },
	{ 0x91, 0x53, L'全' },
	{ 0x91, 0x54, L'禅' },
	{ 0x91, 0x63, L'祖' },
	{ 0x91, 0x6F, L'双' },
	{ 0x91, 0x71, L'倉' },
	{ 0x91, 0x75, L'爽' },
	{ 0x91, 0x76, L'宋' },
	{ 0x91, 0x80, L'操' },
	{ 0x91, 0x82, L'曹' },
	{ 0x91, 0x8E, L'綜' },
	{ 0x91, 0xB1, L'続' },
	{ 0x91, 0xB7, L'孫' },
	{ 0x91, 0xBB, L'遜' },
	{ 0x91, 0xBE, L'太' },
	{ 0x91, 0xD0, L'岱' },
	{ 0x91, 0xD7, L'泰' },
	{ 0x91, 0xEC, L'卓' },
	{ 0x91, 0xF2, L'沢' },

	{ 0x92, 0x42, L'達' },
	{ 0x92, 0x58, L'湛' },
	{ 0x92, 0x61, L'誕' },
	{ 0x92, 0x87, L'仲' },
	{ 0x92, 0x89, L'忠' },
	{ 0x92, 0x98, L'著' },
	{ 0x92, 0x9A, L'丁' },
	{ 0x92, 0x9E, L'寵' },
	{ 0x92, 0xA3, L'張' },
	{ 0x92, 0xB4, L'超' },
	{ 0x92, 0xC2, L'陳' },
	{ 0x92, 0xCA, L'通' },
	{ 0x92, 0xE8, L'定' },
	{ 0x92, 0xF6, L'程' },

	{ 0x93, 0x53, L'鉄' },
	{ 0x93, 0x54, L'典' },
	{ 0x93, 0x63, L'田' },
	{ 0x93, 0x6D, L'杜' },
	{ 0x93, 0x6F, L'登' },
	{ 0x93, 0x78, L'度' },
	{ 0x93, 0x7A, L'奴' },
	{ 0x93, 0x96, L'当' },
	{ 0x93, 0x9D, L'統' },
	{ 0x93, 0x9F, L'董' },
	{ 0x93, 0xA9, L'陶' },
	{ 0x93, 0xAB, L'騰' },
	{ 0x93, 0xAF, L'同' },
	{ 0x93, 0xB9, L'道' },
	{ 0x93, 0xBF, L'徳' },
	{ 0x93, 0xD5, L'惇' },
	{ 0x93, 0xEC, L'南' },

	{ 0x94, 0x43, L'任' },
	{ 0x94, 0x4A, L'寧' },
	{ 0x94, 0x56, L'之' },
	{ 0x94, 0x62, L'巴' },
	{ 0x94, 0x65, L'覇' },
	{ 0x94, 0x6E, L'馬' },
	{ 0x94, 0x7A, L'配' },
	{ 0x94, 0x90, L'柏' },
	{ 0x94, 0x96, L'薄' },
	{ 0x94, 0xC7, L'班' },
	{ 0x94, 0xCD, L'範' },
	{ 0x94, 0xD6, L'磐' },
	{ 0x94, 0xEF, L'費' },
	{ 0x94, 0xF2, L'飛' },
	{ 0x94, 0xF5, L'備' },
	{ 0x94, 0xF9, L'毘' },

	{ 0x95, 0x5C, L'表' },
	{ 0x95, 0x5D, L'評' },
	{ 0x95, 0x5E, L'豹' },
	{ 0x95, 0x7A, L'布' },
	{ 0x95, 0x81, L'普' },
	{ 0x95, 0x90, L'武' },
	{ 0x95, 0x95, L'封' },
	{ 0x95, 0xA3, L'淵' },
	{ 0x95, 0xB6, L'文' },
	{ 0x95, 0xBD, L'平' },
	{ 0x95, 0xDE, L'圃' },
	{ 0x95, 0xE0, L'歩' },
	{ 0x95, 0xF2, L'奉' },

	{ 0x96, 0x40, L'法' },
	{ 0x96, 0x46, L'芳' },
	{ 0x96, 0x47, L'萌' },
	{ 0x96, 0x4A, L'褒' },
	{ 0x96, 0x4C, L'豊' },
	{ 0x96, 0x50, L'鳳' },
	{ 0x96, 0x7C, L'翻' },
	{ 0x96, 0x80, L'摩' },
	{ 0x96, 0x9E, L'満' },
	{ 0x96, 0xD0, L'孟' },
	{ 0x96, 0xD1, L'毛' },
	{ 0x96, 0xD6, L'蒙' },
	{ 0x96, 0xD9, L'黙' },
	{ 0x96, 0xF5, L'靖' },

	{ 0x97, 0x44, L'優' },
	{ 0x97, 0x48, L'幽' },
	{ 0x97, 0x59, L'雄' },
	{ 0x97, 0x5A, L'融' },
	{ 0x97, 0x5C, L'予' },
	{ 0x97, 0x67, L'揚' },
	{ 0x97, 0x6B, L'楊' },
	{ 0x97, 0x96, L'蘭' },
	{ 0x97, 0x97, L'覧' },
	{ 0x97, 0x9B, L'李' },
	{ 0x97, 0xA4, L'陸' },
	{ 0x97, 0xAB, L'劉' },
	{ 0x97, 0x83, L'翼' },
	{ 0x97, 0x8B, L'雷' },
	{ 0x97, 0xB4, L'龍' },
	{ 0x97, 0xBA, L'亮' },
	{ 0x97, 0xBD, L'凌' },
	{ 0x97, 0xC0, L'梁' },
	{ 0x97, 0xC1, L'涼' },
	{ 0x97, 0xC7, L'良' },
	{ 0x97, 0xC9, L'遼' },
	{ 0x97, 0xDD, L'累' },
	{ 0x97, 0xE2, L'冷' },
	{ 0x97, 0xE7, L'礼' },
	{ 0x97, 0xEE, L'齢' },
	{ 0x97, 0xEC, L'霊' },

	{ 0x98, 0x43, L'呂' },
	{ 0x98, 0x44, L'魯' },
	{ 0x98, 0x4E, L'朗' },
	{ 0x98, 0x61, L'和' },
	{ 0x98, 0xA1, L'丕' },
	{ 0x98, 0xB0, L'于' },
	{ 0x98, 0xC2, L'伉' },
	{ 0x98, 0xFA, L'傅' },

	{ 0x99, 0x62, L'冀' },
	{ 0x99, 0xAC, L'勳' },

	{ 0x9A, 0x66, L'喃' },
	{ 0x9A, 0xF3, L'奕' },

	{ 0x9B, 0x49, L'姜' },
	{ 0x9B, 0x9A, L'尹' },
	{ 0x9B, 0xA8, L'岑' },
	{ 0x9B, 0xD6, L'嶷' },

	{ 0x9C, 0x40, L'廖' },
	{ 0x9C, 0x8D, L'恪' },
	{ 0x9C, 0xF2, L'懿' },

	{ 0x9D, 0xBF, L'攸' },
	{ 0x9D, 0xD5, L'旌' },
	{ 0x9D, 0xDF, L'旻' },
	{ 0x9D, 0xF9, L'暹' },

	{ 0x9E, 0x40, L'曄' },
	{ 0x9E, 0x44, L'曠' },
	{ 0x9E, 0x53, L'朶' },
	{ 0x9E, 0xB2, L'楷' },
	{ 0x9E, 0xBC, L'楙' },
	{ 0x9E, 0xE6, L'樊' },

	{ 0x9F, 0x78, L'毋' },
	{ 0x9F, 0x8F, L'沛' },
	{ 0x9F, 0x9C, L'沮' },
	{ 0x9F, 0xCC, L'淮' },

	{ 0xE0, 0x4E, L'潘' },
	{ 0xE0, 0x5C, L'濬' },
	{ 0xE0, 0x81, L'焉' },
	{ 0xE0, 0x86, L'煕' },
	{ 0xE0, 0xEE, L'瑁' },
	{ 0xE0, 0xEF, L'瑜' },
	{ 0xE0, 0xF5, L'瑾' },
	{ 0xE0, 0xF6, L'璋' },
	{ 0xE0, 0xF9, L'瓊' },

	{ 0xE1, 0x64, L'疆' },

	{ 0xE2, 0x5C, L'秉' },
	{ 0xE2, 0x66, L'稠' },
	{ 0xE2, 0xEA, L'粲' },
	{ 0xE2, 0xEB, L'粱' },
	{ 0xE2, 0xF4, L'糜' },

	{ 0xE3, 0xC2, L'翊' },
	{ 0xE3, 0xC4, L'翔' },
	{ 0xE3, 0xD9, L'聘' },

	{ 0xE4, 0x88, L'艾' },
	{ 0xE4, 0x97, L'范' },
	{ 0xE4, 0x9A, L'苞' },
	{ 0xE4, 0xB6, L'荼' },
	{ 0xE4, 0xA4, L'荀' },

	{ 0xE5, 0x4C, L'薛' },
	{ 0xE5, 0x69, L'虔' },
	{ 0xE5, 0xCD, L'袁' },

	{ 0xE6, 0x8C, L'謖' },
	{ 0xE6, 0x9D, L'譚' },
	{ 0xE6, 0xC9, L'賈' },
	{ 0xE6, 0xE2, L'趙' },

	{ 0xE7, 0x66, L'軫' },
	{ 0xE7, 0x9C, L'逵' },

	{ 0xE8, 0x85, L'閻' },
	{ 0xE8, 0xB4, L'雍' },
	{ 0xE8, 0xB7, L'霍' },
	{ 0xE8, 0xDD, L'鞏' },
	{ 0xE8, 0xE8, L'韋' },

	{ 0xE9, 0x65, L'馥' },
	{ 0xE9, 0xB0, L'魏' },
	{ 0xE9, 0xB5, L'魴' },
	{ 0xE9, 0xB8, L'鮑' },

	{ 0xEB, 0x9F, L'瓉' },		// TODO
	{ 0xEB, 0xA0, L'昱' },		// TODO
	{ 0xEB, 0xA1, L'彧' },		// TODO
	{ 0xEB, 0xA2, L'郃' },		// TODO
	{ 0xEB, 0xA3, L'蒯' },		// TODO
	{ 0xEB, 0xA4, L'蔡' },		// TODO
	{ 0xEB, 0xA5, L'傕' },		// TODO
	{ 0xEB, 0xA7, L'汜' },		// TODO
	{ 0xEB, 0xA8, L'詡' },		// TODO
	{ 0xEB, 0xA9, L'鄧' },		// TODO
	{ 0xEB, 0xAA, L'充' },		// TODO
	{ 0xEB, 0xAB, L'龐' },		// TODO
	{ 0xEB, 0xAC, L'繇' },		// TODO
	{ 0xEB, 0xAD, L'邈' },		// TODO
	{ 0xEB, 0xAE, L'騭' },		// TODO
	{ 0xEB, 0xAF, L'畯' },		// TODO
	{ 0xEB, 0xB0, L'闞' },		// TODO
	{ 0xEB, 0xB1, L'玠' },		// TODO
	{ 0xEB, 0xB2, L'顗' },		// TODO
	{ 0xEB, 0xB3, L'邢' },		// TODO
	{ 0xEB, 0xB4, L'歆' },		// TODO
	{ 0xEB, 0xB5, L'闓' },		// TODO
	{ 0xEB, 0xB6, L'禕' },		// TODO
	{ 0xEB, 0xB8, L'琬' },		// TODO
	{ 0xEB, 0xB9, L'郝' },		// TODO
	{ 0xEB, 0xBA, L'琮' },		// TODO
	{ 0xEB, 0xBC, L'褚' },		// TODO
	{ 0xEB, 0xC0, L'琦' },		// TODO
	{ 0xEB, 0xC1, L'琮' },		// TODO
	{ 0xEB, 0xC3, L'并' },		// TODO
	{ 0xEB, 0xC4, L'璝' },		// TODO
	{ 0xEB, 0xC6, L'彤' },		// TODO
};

wchar_t CodeTbl::Convert2Shiftjis(unsigned char code1, unsigned char code2)
{
	wchar_t ret = L'無';
	int CodeTblItemCount = sizeof(CodeTbl2) / sizeof(CODE_ITEM2);

	for (int i = 0; i < CodeTblItemCount; i++) {
		if ((code1 == CodeTbl2[i].code1) &&
			(code2 == CodeTbl2[i].code2)
		) {
			ret = CodeTbl2[i].word;
			CodeTbl2[i].counter++;
		}
	}

	return ret;
}

void CodeTbl::ConvertGeneralName1(unsigned char* name1, wchar_t* name1_disp)
{
	unsigned char code1;
	unsigned char code2;
	int offset = 0;
	int offset2 = 0;
	wchar_t word;

	while(1) {
		code1 = name1[offset];
		if (code1 == 0) {
			break;
		}
		code2 = name1[offset + 1];
		offset += 2;

		word = Convert2Shiftjis(code1, code2);
		name1_disp[offset2] = word;
		offset2++;
	}

	name1_disp[offset2] = 0;
}


CODE_ITEM1 CodeTbl1[] = {
	{ 0x0A, L'\n' },
	{ 0x20, L' ' }, { 0x21, L'!' },
	{ 0x22, L'\"' }, { 0x23, L'#' },
	{ 0x24, L'$' }, { 0x25, L'%' },
	{ 0x26, L'&' }, { 0x27, L'\'' },
	{ 0x28, L'(' }, { 0x29, L')' },
	{ 0x2A, L'*' }, { 0x2B, L'+' },
	{ 0x2C, L',' }, { 0x2D, L'-' },
	{ 0x2E, L'.' }, { 0x2F, L'/' },
	
	{ 0x30, L'0' }, { 0x31, L'1' },
	{ 0x32, L'2' }, { 0x33, L'3' },
	{ 0x34, L'4' }, { 0x35, L'5' },
	{ 0x36, L'6' }, { 0x37, L'7' },
	{ 0x38, L'8' }, { 0x39, L'9' },
	{ 0x3A, L':' }, { 0x3B, L';' },
	{ 0x3C, L'<' }, { 0x3D, L'=' },
	{ 0x3E, L'>' }, { 0x3F, L'?' },

	{ 0x40, L'@' }, { 0x41, L'A' },
	{ 0x42, L'B' }, { 0x43, L'C' },
	{ 0x44, L'D' }, { 0x45, L'E' },
	{ 0x46, L'F' }, { 0x47, L'G' },
	{ 0x48, L'H' }, { 0x49, L'I' },
	{ 0x4A, L'J' }, { 0x4B, L'K' },
	{ 0x4C, L'L' }, { 0x4D, L'M' },
	{ 0x4E, L'N' }, { 0x4F, L'O' },

	{ 0x50, L'P' }, { 0x51, L'Q' },
	{ 0x52, L'R' }, { 0x53, L'S' },
	{ 0x54, L'T' }, { 0x55, L'U' },
	{ 0x56, L'V' }, { 0x57, L'W' },
	{ 0x58, L'X' }, { 0x59, L'Y' },
	{ 0x5A, L'Z' }, { 0x5B, L'[' },
	{ 0x5C, L'¥' }, { 0x5D, L']' },
	{ 0x5E, L'^' }, { 0x5F, L'_' },

	{ 0x60, L'`' }, { 0x61, L'a' },
	{ 0x62, L'b' }, { 0x63, L'c' },
	{ 0x64, L'd' }, { 0x65, L'e' },
	{ 0x66, L'f' }, { 0x67, L'g' },
	{ 0x68, L'h' }, { 0x69, L'i' },
	{ 0x6A, L'j' }, { 0x6B, L'k' },
	{ 0x6C, L'l' }, { 0x6D, L'm' },
	{ 0x6E, L'n' }, { 0x6F, L'o' },

	{ 0x70, L'p' }, { 0x71, L'q' },
	{ 0x72, L'r' }, { 0x73, L's' },
	{ 0x74, L't' }, { 0x75, L'u' },
	{ 0x76, L'v' }, { 0x77, L'w' },
	{ 0x78, L'x' }, { 0x79, L'y' },
	{ 0x7A, L'z' }, { 0x7B, L'{' },
	{ 0x7C, L'|' }, { 0x7D, L'}' },
	{ 0x7E, L'‾' },

	{ 0xA1, L'｡' },
	{ 0xA2, L'｢' }, { 0xA3, L'｣' },
	// { 0xA4, L'､' },
	{ 0xA4, L',' }, { 0xA5, L'･' },
	{ 0xA6, L'を' }, { 0xA7, L'ぁ' },
	{ 0xA8, L'ぃ' }, { 0xA9, L'ぅ' },
	{ 0xAA, L'ぇ' }, { 0xAB, L'ぉ' },
	{ 0xAC, L'ゃ' }, { 0xAD, L'ゅ' },
	{ 0xAE, L'ょ' }, { 0xAF, L'っ' },

	{ 0xB0, L'ｰ' }, { 0xB1, L'あ' },
	{ 0xB2, L'い' }, { 0xB3, L'う' },
	{ 0xB4, L'え' }, { 0xB5, L'お' },
	{ 0xB6, L'か' }, { 0xB7, L'き' },
	{ 0xB8, L'く' }, { 0xB9, L'け' },
	{ 0xBA, L'こ' }, { 0xBB, L'さ' },
	{ 0xBC, L'し' }, { 0xBD, L'す' },
	{ 0xBE, L'せ' }, { 0xBF, L'そ' },

	{ 0xC0, L'た' }, { 0xC1, L'ち' },
	{ 0xC2, L'つ' }, { 0xC3, L'て' },
	{ 0xC4, L'と' }, { 0xC5, L'な' },
	{ 0xC6, L'に' }, { 0xC7, L'ぬ' },
	{ 0xC8, L'ね' }, { 0xC9, L'の' },
	{ 0xCA, L'は' }, { 0xCB, L'ひ' },
	{ 0xCC, L'ふ' }, { 0xCD, L'へ' },
	{ 0xCE, L'ほ' }, { 0xCF, L'ま' },

	{ 0xD0, L'み' }, { 0xD1, L'む' },
	{ 0xD2, L'め' }, { 0xD3, L'も' },
	{ 0xD4, L'や' }, { 0xD5, L'ゆ' },
	{ 0xD6, L'よ' }, { 0xD7, L'ら' },
	{ 0xD8, L'り' }, { 0xD9, L'る' },
	{ 0xDA, L'れ' }, { 0xDB, L'ろ' },
	{ 0xDC, L'わ' }, { 0xDD, L'ん' },
	{ 0xDE, L'"' }, { 0xDF, L'~' },			// TODO
	//{ 0xDE, L'ﾞ' }, { 0xDF, L'ﾟ' },
};

wchar_t CodeTbl::Convert2Shiftjis(unsigned char code1)
{
	wchar_t ret = L'無';
	int CodeTblItemCount = sizeof(CodeTbl1) / sizeof(CODE_ITEM1);

	for (int i = 0; i < CodeTblItemCount; i++) {
		if ((code1 == CodeTbl1[i].code1)
			) {
			ret = CodeTbl1[i].word;
			CodeTbl1[i].counter++;
		}
	}

	if (ret == L'無') {
		cout << "[" << (int)code1 << "]";
	}

	return ret;
}


void CodeTbl::ConvertGeneralName2(unsigned char* name2, wchar_t* name2_disp)
{
	unsigned char code;
	int offset = 0;
	wchar_t word;

	while (1) {
		code = name2[offset];
		if (code == 0) {
			break;
		}

		word = Convert2Shiftjis(code);
		name2_disp[offset] = word;
		offset++;
	}

	name2_disp[offset] = 0;
}

void CodeTbl::ConvertProvinceName1(unsigned char* name1, wchar_t* name1_disp)
{
	unsigned char code1;
	unsigned char code2;
	int offset = 0;
	int offset2 = 0;
	wchar_t word;

	while (1) {
		code1 = name1[offset];
		if (code1 == 0) {
			break;
		}
		code2 = name1[offset + 1];
		offset += 2;

		word = Convert2Shiftjis(code1, code2);
		name1_disp[offset2] = word;
		offset2++;
	}

	name1_disp[offset2] = 0;
}


void CodeTbl::ConvertProvinceName2(unsigned char* name2, wchar_t* name2_disp)
{
	unsigned char code;
	int offset = 0;
	wchar_t word;

	while (1) {
		code = name2[offset];
		if (code == 0) {
			break;
		}

		word = Convert2Shiftjis(code);
		name2_disp[offset] = word;
		offset++;
	}

	name2_disp[offset] = 0;
}