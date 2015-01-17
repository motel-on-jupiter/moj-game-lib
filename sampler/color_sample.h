/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_SAMPLER_COLORSAMPLER_H_
#define MOJGAMELIB_SAMPLER_COLORSAMPLER_H_

namespace mojgame {

// Web colors (http://www.w3.org/TR/REC-html40/types.html#h-6.5)
namespace WebColor {
static const unsigned char kBlack[] = { 0x00, 0x00, 0x00 };
static const unsigned char kSilver[] = { 0xC0, 0xC0, 0xC0 };
static const unsigned char kGray[] = { 0x80, 0x80, 0x80 };
static const unsigned char kWhite[] = { 0xFF, 0xFF, 0xFF };
static const unsigned char kMaroon[] = { 0x80, 0x00, 0x00 };
static const unsigned char kRed[] = { 0xFF, 0x00, 0x00 };
static const unsigned char kPurple[] = { 0x80, 0x00, 0x80 };
static const unsigned char kFuchsia[] = { 0xFF, 0x00, 0xFF };
static const unsigned char kGreen[] = { 0x00, 0x80, 0x00 };
static const unsigned char kLime[] = { 0x00, 0xFF, 0x00 };
static const unsigned char kOlive[] = { 0x80, 0x80, 0x00 };
static const unsigned char kYellow[] = { 0xFF, 0xFF, 0x00 };
static const unsigned char kNavy[] = { 0x00, 0x00, 0x80 };
static const unsigned char kBlue[] = { 0x00, 0x00, 0xFF };
static const unsigned char kTeal[] = { 0x00, 0x80, 0x80 };
static const unsigned char kAqua[] = { 0x00, 0xFF, 0xFF };
} /* namespace WebColor */

// X11 colors (http://www.w3.org/TR/css3-color/#svg-color)
namespace X11Color {
static const unsigned char kAliceBlue[] = { 0xF0, 0xF8, 0xFF };
static const unsigned char kAntiqueWhite[] = { 0xFA, 0xED, 0xD7 };
static const unsigned char kAqua[] = { 0x00, 0xFF, 0xFF };
static const unsigned char kAquaMarine[] = { 0x7F, 0xFF, 0xD4 };
static const unsigned char kAzure[] = { 0xF0, 0xFF, 0xFF };
static const unsigned char kBeige[] = { 0xF5, 0xF5, 0xDC };
static const unsigned char kBisque[] = { 0xFF, 0xE4, 0xC4 };
static const unsigned char kBlack[] = { 0x00, 0x00, 0x00 };
static const unsigned char kBlanchedAlmond[] = { 0xFF, 0xEB, 0xCD };
static const unsigned char kBlue[] = { 0x00, 0x00, 0xFF };
static const unsigned char kBlueViolet[] = { 0x8A, 0x2B, 0xE2 };
static const unsigned char kBrown[] = { 0xA5, 0x2A, 0x2A };
static const unsigned char kBurlyWood[] = { 0xDE, 0xB8, 0x87 };
static const unsigned char kCadetBlue[] = { 0x5F, 0x9E, 0xA0 };
static const unsigned char kChartreuse[] = { 0x7F, 0xFF, 0x00 };
static const unsigned char kChocolate[] = { 0xD2, 0x69, 0x1E };
static const unsigned char kCoral[] = { 0xFF, 0x7F, 0x50 };
static const unsigned char kCornFlowerBlue[] = { 0x64, 0x95, 0xED };
static const unsigned char kCornSilk[] = { 0xFF, 0xF8, 0xDC };
static const unsigned char kCrimson[] = { 0xDC, 0x14, 0x3C };
static const unsigned char kCyan[] = { 0x00, 0xFF, 0xFF };
static const unsigned char kDarkBlue[] = { 0x00, 0x00, 0x8B };
static const unsigned char kDarkCyan[] = { 0x00, 0x8B, 0x8B };
static const unsigned char kDarkGoldenRod[] = { 0xB8, 0x86, 0x0B };
static const unsigned char kDarkGray[] = { 0xA9, 0xA9, 0xA9 };
static const unsigned char kDarkGreen[] = { 0x00, 0x64, 0x00 };
static const unsigned char kDarkGrey[] = { 0xA9, 0xA9, 0xA9 };
static const unsigned char kDarkKhaki[] = { 0xBD, 0xB7, 0x6B };
static const unsigned char kDarkMagenta[] = { 0x8B, 0x00, 0x8B };
static const unsigned char kDarkOliveGreen[] = { 0x55, 0x6B, 0x2F };
static const unsigned char kDarkOrange[] = { 0xFF, 0x8C, 0x00 };
static const unsigned char kDarkOrchid[] = { 0x99, 0x32, 0xCC };
static const unsigned char kDarkRed[] = { 0x8B, 0x00, 0x00 };
static const unsigned char kDarkSalmon[] = { 0xE9, 0x96, 0x7A };
static const unsigned char kDarkSeagreen[] = { 0x8F, 0xBC, 0x8F };
static const unsigned char kDarkSlateBlue[] = { 0x48, 0x3D, 0x8B };
static const unsigned char kDarkSlateGray[] = { 0x2F, 0x4F, 0x4F };
static const unsigned char kDarkSlateGrey[] = { 0x2F, 0x4F, 0x4F };
static const unsigned char kDarkTurquoise[] = { 0x00, 0xCE, 0xD1 };
static const unsigned char kDarkViolet[] = { 0x94, 0x00, 0xD3 };
static const unsigned char kDeepPink[] = { 0xFF, 0x14, 0x93 };
static const unsigned char kDeepSkyBlue[] = { 0x00, 0xBF, 0xFF };
static const unsigned char kDimGray[] = { 0x69, 0x69, 0x69 };
static const unsigned char kDimGrey[] = { 0x69, 0x69, 0x69 };
static const unsigned char kDodgerBlue[] = { 0x1E, 0x90, 0xFF };
static const unsigned char kFireBrick[] = { 0xB2, 0x22, 0x22 };
static const unsigned char kFloralWhite[] = { 0xFF, 0xFA, 0xF0 };
static const unsigned char kForestGreen[] = { 0x22, 0x8B, 0x22 };
static const unsigned char kFuchsia[] = { 0xFF, 0x00, 0xFF };
static const unsigned char kGainsboro[] = { 0xDC, 0xDC, 0xDC };
static const unsigned char kGhostWhite[] = { 0xF8, 0xF8, 0xFF };
static const unsigned char kGold[] = { 0xFF, 0xD7, 0x00 };
static const unsigned char kGoldenRod[] = { 0xDA, 0xA5, 0x20 };
static const unsigned char kGray[] = { 0x80, 0x80, 0x80 };
static const unsigned char kGreen[] = { 0x00, 0x80, 0x00 };
static const unsigned char kGreenYellow[] = { 0xAD, 0xFF, 0x2F };
static const unsigned char kGrey[] = { 0x80, 0x80, 0x80 };
static const unsigned char kHoneydew[] = { 0xF0, 0xFF, 0xF0 };
static const unsigned char kHotPink[] = { 0xFF, 0x69, 0xB4 };
static const unsigned char kIndianRed[] = { 0xCD, 0x5C, 0x5C };
static const unsigned char kIndigo[] = { 0x4B, 0x00, 0x82 };
static const unsigned char kIvory[] = { 0xFF, 0xFF, 0xF0 };
static const unsigned char kKhaki[] = { 0xF0, 0xE6, 0x8C };
static const unsigned char kLavender[] = { 0xE6, 0xE6, 0xFA };
static const unsigned char kLavenderBlush[] = { 0xFF, 0xF0, 0xF5 };
static const unsigned char kLawnGreen[] = { 0x7C, 0xFC, 0x00 };
static const unsigned char kLemonChiffon[] = { 0xFF, 0xFA, 0xCD };
static const unsigned char kLightBlue[] = { 0xAD, 0xD8, 0xE6 };
static const unsigned char kLightCoral[] = { 0xF0, 0x80, 0x80 };
static const unsigned char kLightCyan[] = { 0xE0, 0xFF, 0xFF };
static const unsigned char kLightGoldenRodYellow[] = { 0xFA, 0xFA, 0xD2 };
static const unsigned char kLightGray[] = { 0xD3, 0xD3, 0xD3 };
static const unsigned char kLightGreen[] = { 0x90, 0xEE, 0x90 };
static const unsigned char kLightGrey[] = { 0xD3, 0xD3, 0xD3 };
static const unsigned char kLightPink[] = { 0xFF, 0xB6, 0xC1 };
static const unsigned char kLightSalmon[] = { 0xFF, 0xA0, 0x7A };
static const unsigned char kLightSeaGreen[] = { 0x20, 0xB2, 0xAA };
static const unsigned char kLightSkyBlue[] = { 0x87, 0xCE, 0xFA };
static const unsigned char kLightSlateGray[] = { 0x77, 0x88, 0x99 };
static const unsigned char kLightSlateGrey[] = { 0x77, 0x88, 0x99 };
static const unsigned char kLightSteelBlue[] = { 0xB0, 0xC4, 0xDE };
static const unsigned char kLightYellow[] = { 0xFF, 0xFF, 0xE0 };
static const unsigned char kLime[] = { 0x00, 0xFF, 0x00 };
static const unsigned char kLimeGreen[] = { 0x32, 0xCD, 0x32 };
static const unsigned char kLinen[] = { 0xFA, 0xF0, 0xE6 };
static const unsigned char kMagenta[] = { 0xFF, 0x00, 0xFF };
static const unsigned char kMaroon[] = { 0x80, 0x00, 0x00 };
static const unsigned char kMediumAquaMarine[] = { 0x66, 0xCD, 0xAA };
static const unsigned char kMediumBlue[] = { 0x00, 0x00, 0xCD };
static const unsigned char kMediumOrchid[] = { 0xBA, 0x55, 0xD3 };
static const unsigned char kMediumPurple[] = { 0x93, 0x70, 0xDB };
static const unsigned char kMediumSeaGreen[] = { 0x3C, 0xB3, 0x71 };
static const unsigned char kMediumSlateBlue[] = { 0x7B, 0x68, 0xEE };
static const unsigned char kMediumSpringGreen[] = { 0x00, 0xFA, 0x9A };
static const unsigned char kMediumTurquoise[] = { 0x48, 0xD1, 0xCC };
static const unsigned char kMediumVioletRed[] = { 0xC7, 0x15, 0x85 };
static const unsigned char kMidnightBlue[] = { 0x19, 0x19, 0x70 };
static const unsigned char kMintCream[] = { 0xF5, 0xFF, 0xFA };
static const unsigned char kMistyRose[] = { 0xFF, 0xE4, 0xE1 };
static const unsigned char kMoccasin[] = { 0xFF, 0xE4, 0xB5 };
static const unsigned char kNavajoWhite[] = { 0xFF, 0xDE, 0xAD };
static const unsigned char kNavy[] = { 0x00, 0x00, 0x80 };
static const unsigned char kOldLace[] = { 0xFD, 0xF5, 0xE6 };
static const unsigned char kOlive[] = { 0x80, 0x80, 0x00 };
static const unsigned char kOliveDrab[] = { 0x6B, 0x8E, 0x23 };
static const unsigned char kOrange[] = { 0xFF, 0xA5, 0x00 };
static const unsigned char kOrangeRed[] = { 0xFF, 0x45, 0x00 };
static const unsigned char kOrchid[] = { 0xDA, 0x70, 0xD6 };
static const unsigned char kPaleGoldenRod[] = { 0xEE, 0xE8, 0xAA };
static const unsigned char kPaleGreen[] = { 0x98, 0xFB, 0x98 };
static const unsigned char kPaleTurquoise[] = { 0xAF, 0xEE, 0xEE };
static const unsigned char kPaleVioletRed[] = { 0xDB, 0x70, 0x93 };
static const unsigned char kPapayaWhip[] = { 0xFF, 0xEF, 0xD5 };
static const unsigned char kPeachPuff[] = { 0xFF, 0xDA, 0xB9 };
static const unsigned char kPeru[] = { 0xCD, 0x85, 0x3F };
static const unsigned char kPink[] = { 0xFF, 0xC0, 0xCB };
static const unsigned char kPlum[] = { 0xDD, 0xA0, 0xDD };
static const unsigned char kPowderBlue[] = { 0xB0, 0xE0, 0xE6 };
static const unsigned char kPurple[] = { 0x80, 0x00, 0x80 };
static const unsigned char kRed[] = { 0xFF, 0x00, 0x00 };
static const unsigned char kRosyBrown[] = { 0xBC, 0x8F, 0x8F };
static const unsigned char kRoyalBlue[] = { 0x41, 0x69, 0xE1 };
static const unsigned char kSaddleBrown[] = { 0x8B, 0x45, 0x13 };
static const unsigned char kSalmon[] = { 0xFA, 0x80, 0x72 };
static const unsigned char kSandyBrown[] = { 0xF4, 0xA4, 0x60 };
static const unsigned char kSeaGreen[] = { 0x2E, 0x8B, 0x57 };
static const unsigned char kSeaShell[] = { 0xFF, 0xF5, 0xEE };
static const unsigned char kSienna[] = { 0xA0, 0x52, 0x2D };
static const unsigned char kSilver[] = { 0xC0, 0xC0, 0xC0 };
static const unsigned char kSkyBlue[] = { 0x87, 0xCE, 0xEB };
static const unsigned char kSlateBlue[] = { 0x6A, 0x5A, 0xCD };
static const unsigned char kSlateGray[] = { 0x70, 0x80, 0x90 };
static const unsigned char kSlateGrey[] = { 0x70, 0x80, 0x90 };
static const unsigned char kSnow[] = { 0xFF, 0xFA, 0xFA };
static const unsigned char kSpringGreen[] = { 0x00, 0xFF, 0x7F };
static const unsigned char kSteelBlue[] = { 0x46, 0x82, 0xB4 };
static const unsigned char kTan[] = { 0xD2, 0xB4, 0x8C };
static const unsigned char kTeal[] = { 0x00, 0x80, 0x80 };
static const unsigned char kThistle[] = { 0xD8, 0xBF, 0xD8 };
static const unsigned char kTomato[] = { 0xFF, 0x63, 0x47 };
static const unsigned char kTurquoise[] = { 0x40, 0xE0, 0xD0 };
static const unsigned char kViolet[] = { 0xEE, 0x82, 0xEE };
static const unsigned char kWheat[] = { 0xF5, 0xDE, 0xB3 };
static const unsigned char kWhite[] = { 0xFF, 0xFF, 0xFF };
static const unsigned char kWhiteSmoke[] = { 0xF5, 0xF5, 0xF5 };
static const unsigned char kYellow[] = { 0xFF, 0xFF, 0x00 };
static const unsigned char kYellowGreen[] = { 0x9A, 0xCD, 0x32 };
} /* namespace X11Color */

namespace color_sample {
extern glm::vec3 to_fvec(const unsigned char (&color)[3]);
} /* namespace color_sample */

} /* namespace mojgame */

#endif /* MOJGAMELIB_SAMPLER_COLORSAMPLER_H_ */
