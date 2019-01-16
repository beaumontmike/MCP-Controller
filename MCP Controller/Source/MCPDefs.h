#define UBRRH

#ifndef MCPDEFS_H_
#define MCPDEFS_H_

#include "Arduino.h"
#include "MCPKey.h"

constexpr char* DEVICE_NAME("MCP Panel v0.1a");
String DEVICE_NAME_QUERY("QUERY_DEVICE_NAME");

constexpr long SERIAL_BAUD = 115200;

constexpr uint8_t D02 = 2;  constexpr uint8_t D03 = 3;  constexpr uint8_t D04 = 4;  constexpr uint8_t D05 = 5;
constexpr uint8_t D06 = 6;  constexpr uint8_t D07 = 7;  constexpr uint8_t D08 = 8;  constexpr uint8_t D09 = 9;
constexpr uint8_t D10 = 10; constexpr uint8_t D11 = 11; constexpr uint8_t D12 = 12; constexpr uint8_t D13 = 13;
constexpr uint8_t D14 = 14; constexpr uint8_t D15 = 15; constexpr uint8_t D16 = 16; constexpr uint8_t D17 = 17;
constexpr uint8_t D18 = 18; constexpr uint8_t D19 = 19; constexpr uint8_t D20 = 20; constexpr uint8_t D21 = 21;
constexpr uint8_t D22 = 22; constexpr uint8_t D23 = 23; constexpr uint8_t D24 = 24; constexpr uint8_t D25 = 25;
constexpr uint8_t D26 = 26; constexpr uint8_t D27 = 27; constexpr uint8_t D28 = 28; constexpr uint8_t D29 = 29;
constexpr uint8_t D30 = 30; constexpr uint8_t D31 = 31; constexpr uint8_t D32 = 32; constexpr uint8_t D33 = 33;
constexpr uint8_t D34 = 34; constexpr uint8_t D35 = 35; constexpr uint8_t D36 = 36; constexpr uint8_t D37 = 37;
constexpr uint8_t D38 = 38; constexpr uint8_t D39 = 39;


MCPKey AP_ATH_FLC		= MCPKey(D10, D34, INPUT_PULLUP, "AP_ATH_FLC"); 		// Placeholder pin values.
MCPKey AP_ATH_SPD		= MCPKey(D11, D35, INPUT_PULLUP, "AP_ATH_SPD");
// MCPKey AP_ATH_N1		= MCPKey(D16, D17, INPUT_PULLUP, "AP_ATH_N1");
// MCPKey AP_ATH_VNAV 		= MCPKey(D18, D19, INPUT_PULLUP, "AP_ATH_VNAV");
MCPKey AP_HDG_SEL		= MCPKey(D09, D33, INPUT_PULLUP, "AP_HDG_SEL"); 	// Temp to pins 12,13
MCPKey AP_HDG_LNAV 		= MCPKey(D08, D32, INPUT_PULLUP, "AP_HDG_LNAV");
//MCPKey AP_HDG_VOR		= MCPKey(D24, D25, INPUT_PULLUP, "AP_HDG_VOR");
//MCPKey AP_HDG_APP		= MCPKey(D26, D27, INPUT_PULLUP, "AP_HDG_APP");
MCPKey AP_ALT_HLD		= MCPKey(D07, D31, INPUT_PULLUP, "AP_ALT_HLD");
MCPKey AP_ALT_VSPD		= MCPKey(D06, D30, INPUT_PULLUP, "AP_LT_VSPD");
MCPKey AP_CMD_A			= MCPKey(D04, D28, INPUT_PULLUP, "AP_CMD_A");
MCPKey AP_CWS_A			= MCPKey(D05, D29, INPUT_PULLUP, "AP_CWS_A");
//MCPKey AP_CMD_B			= MCPKey(D36, D37, INPUT_PULLUP, "AP_CMD_B");
//MCPKey AP_CWS_B			= MCPKey(D38, D39, INPUT_PULLUP, "AP_CWS_B");

MCPKey *Keys[] = {
		&AP_ATH_FLC,
		&AP_ATH_SPD,
//		&AP_ATH_N1,
//		&AP_ATH_VNAV,
		&AP_HDG_SEL,
		&AP_HDG_LNAV,
//		&AP_HDG_VOR,
//		&AP_HDG_APP,
		&AP_ALT_HLD,
		&AP_ALT_VSPD,
		&AP_CMD_A,
		&AP_CWS_A,
//		&AP_CMD_B,
//		&AP_CWS_B,
};


#endif
