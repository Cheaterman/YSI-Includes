/*+
 * <library name="y_version">
 * <section>
 *  Description
 * </section>
 *  Checks online to see if there is a newer version of YSI available.
 * <section>
 *  Version
 * </section>
 *  0.2
 * <section>
 *  Hooks
 * </section><ul>
 *  <symbol name="OnGameModeInit">Initialises things.</symbol>
 * </ul>
 * </library>
 *//** *//*
Legal:
	Version: MPL 1.1
	
	The contents of this file are subject to the Mozilla Public License Version 
	1.1 the "License"; you may not use this file except in compliance with 
	the License. You may obtain a copy of the License at 
	http://www.mozilla.org/MPL/
	
	Software distributed under the License is distributed on an "AS IS" basis,
	WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
	for the specific language governing rights and limitations under the
	License.
	
	The Original Code is the YSI framework.
	
	The Initial Developer of the Original Code is Alex "Y_Less" Cole.
	Portions created by the Initial Developer are Copyright C 2011
	the Initial Developer. All Rights Reserved.

Contributors:
	Y_Less
	koolk
	JoeBullet/Google63
	g_aSlice/Slice
	Misiur
	samphunter
	tianmeta
	maddinat0r
	spacemud
	Crayder
	Dayvison
	Ahmad45123
	Zeex
	irinel1996
	Yiin-
	Chaprnks
	Konstantinos
	Masterchen09
	Southclaws
	PatchwerkQWER
	m0k1
	paulommu
	udan111

Thanks:
	JoeBullet/Google63 - Handy arbitrary ASM jump code using SCTRL.
	ZeeX - Very productive conversations.
	koolk - IsPlayerinAreaEx code.
	TheAlpha - Danish translation.
	breadfish - German translation.
	Fireburn - Dutch translation.
	yom - French translation.
	50p - Polish translation.
	Zamaroht - Spanish translation.
	Los - Portuguese translation.
	Dracoblue, sintax, mabako, Xtreme, other coders - Producing other modes for
		me to strive to better.
	Pixels^ - Running XScripters where the idea was born.
	Matite - Pestering me to release it and using it.

Very special thanks to:
	Thiadmer - PAWN, whose limits continue to amaze me!
	Kye/Kalcor - SA:MP.
	SA:MP Team past, present and future - SA:MP.

Optional plugins:
	Gamer_Z - GPS.
	Incognito - Streamer.
	Me - sscanf2, fixes2, Whirlpool.
*/

CHAIN_HOOK(YVers)
#undef CHAIN_ORDER
#define CHAIN_ORDER CHAIN_NEXT(YVers)

// Amazingly, this fixes hooking OnYSIInit...
CHAIN_FORWARD:YVers_OnYSIInit() = 1;

#define YSI_VERSION_RESPO               2

#define YSI_VERSION_MAJOR               5
#define YSI_VERSION_MINOR               05
#define YSI_VERSION_BUILD               0400

#define YSI_VERSION                     #YSI_VERSION_MAJOR "." #YSI_VERSION_MINOR "." #YSI_VERSION_BUILD

#if defined YSI_NO_VERSION_CHECK && !defined _YSI_NO_VERSION_CHECK
	#define _YSI_NO_VERSION_CHECK
#endif

forward bool:Server_IsWindowsHost();
forward Server_GetJITVersion();

static stock YVers_PrintHeader()
{
	YSI_Print(" ");
	YSI_Print(" ");
	YSI_Print(" ");
	YSI_Print("         ============================================================== ");
	YSI_Print("         |                                                            | ");
	YSI_Print("         |                                                            | ");
	YSI_Print("         |     YYYYYYY       YYYYYYY   SSSSSSSSSSSSSSS IIIIIIIIII     | ");
	YSI_Print("         |     Y:::::Y       Y:::::Y SS:::::::::::::::SI::::::::I     | ");
	YSI_Print("         |     Y:::::Y       Y:::::YS:::::SSSSSS::::::SI::::::::I     | ");
	YSI_Print("         |     Y::::::Y     Y::::::YS:::::S     SSSSSSSII::::::II     | ");
	YSI_Print("         |     YYY:::::Y   Y:::::YYYS:::::S              I::::I       | ");
	YSI_Print("         |        Y:::::Y Y:::::Y   S:::::S              I::::I       | ");
	YSI_Print("         |         Y:::::Y:::::Y     S::::SSSS           I::::I       | ");
	YSI_Print("         |          Y:::::::::Y       SS::::::SSSSS      I::::I       | ");
	YSI_Print("         |           Y:::::::Y          SSS::::::::SS    I::::I       | ");
	YSI_Print("         |            Y:::::Y              SSSSSS::::S   I::::I       | ");
	YSI_Print("         |            Y:::::Y                   S:::::S  I::::I       | ");
	YSI_Print("         |            Y:::::Y                   S:::::S  I::::I       | ");
	YSI_Print("         |            Y:::::Y       SSSSSSS     S:::::SII::::::II     | ");
	YSI_Print("         |         YYYY:::::YYYY    S::::::SSSSSS:::::SI::::::::I     | ");
	YSI_Print("         |         Y:::::::::::Y    S:::::::::::::::SS I::::::::I     | ");
	YSI_Print("         |         YYYYYYYYYYYYY     SSSSSSSSSSSSSSS   IIIIIIIIII     | ");
	YSI_Print("         |                                                            | ");
	YSI_Print("         |                                                            | ");
	YSI_Print("         |                      (c) 2021 MPL v1.1                     | ");
	YSI_Print("         |            Alex \"Y_Less\" Cole and contributors.            | ");
	YSI_Print("         |                                                            | ");
	YSI_Print("         |                                                            | ");
	YSI_Print("         ============================================================== ");
	YSI_Print(" ");
	YSI_Print(" ");
	YSI_Print(" ");
	YSI_Print(" ========================================== ");
	YSI_Print(" |                                        | ");
	YSI_Print(" | Server Version:                        | ");
	YSI_PrintF(" |     %s                            | ", Server_IsWindowsHost() ? ("Windows") : ("Linux  "));
	YSI_Print(" |                                        | ");
	#if ((__Pawn & 0x0F) >= 0x0A)
		YSI_PrintF(" | Compiler Version:                      | ");
		#if __COMPILER_OS == __COMPILER_WINDOWS
			YSI_PrintF(" |     %d.%02d.%02d - Windows                  | ", __Pawn >>> 8, __Pawn & 0xFF, __PawnBuild);
		#else
			YSI_PrintF(" |     %d.%02d.%02d - Linux                    | ", __Pawn >>> 8, __Pawn & 0xFF, __PawnBuild);
		#endif
	#else
		YSI_Print(" | Compiler Version:                      | ");
		YSI_Print(" |     3.2.3664 (Windows)                 | ");
	#endif
	YSI_Print(" |                                        | ");
	YSI_Print(" | YSI Version:                           | ");
	YSI_Print(" |     " YSI_VERSION "                          | ");
	YSI_Print(" |                                        | ");
	YSI_Print(" | JIT Version:                           | ");
	switch (Server_GetJITVersion())
	{
	case 0:
		YSI_Print(" |     <none>                             | ");
	case 1:
		YSI_Print(" |     2.0 or earlier                     | ");
	case 2:
		YSI_Print(" |     2.1 or later                       | ");
	default:
		YSI_Print(" |     <unknown>                          | ");
	}
	YSI_Print(" |                                        | ");
	YSI_Print(" ========================================== ");
}

#if defined _YSI_NO_VERSION_CHECK
	stock YVers_StartCheck()
	{
		#if defined YSI_LOCK_MODE
			new
				x = 10;
			YSI_gLockData[YSI_gLockData[2]++] += (YSI_gLockData[3] = floatround(floatpower(x, 2))) - 2;
			YSI_gLockData[YSI_gLockData[2]++] = (YSI_gLockData[3] | 0x09) & ~0x04;
			YSI_gLockData[2] *= (6 * x) - 5;
		#endif
		return 1;
	}
#else
/*-------------------------------------------------------------------------*//*+
 * <returns>
 *  OnYSIInit
 * </returns>
 * <remarks>
 *      Constructor.  Checks to see if there is a new version available.  This
 *      code can not use ANY of the rest of YSI as it needs to be included by
 *      everything first.
 * </remarks>
 *//*------------------------------------------------------------------------**/
	
	#if !defined HTTP
		stock YVers_StartCheck()
		{
			#if defined YSI_LOCK_MODE
				new
					x = 10;
				YSI_gLockData[0] = 'a' + 1;
				YSI_gLockData[YSI_gLockData[0] - 0x60] = x * 11;
				YSI_gLockData[x / 3] = x * 10;
				YSI_gLockData[1] = (YSI_gLockData[2] - YSI_gLockData[3]) / 2 + YSI_gLockData[3];
			#endif
			YVers_PrintHeader();
			YSI_Print(" |                                        | ");
			YSI_Print(" | Unable to check the latest YSI version | ");
			YSI_Print(" | - please watch the forums and github:  | ");
			YSI_Print(" |                                        | ");
			YSI_Print(" |   https://git.io/5.x                   | ");
			YSI_Print(" |                                        | ");
			YSI_Print(" ========================================== ");
			return 1;
		}
		
		#endinput
	#endif
	
	forward YVers_Callback(index, code, data[]);
	
	stock YVers_StartCheck()
	{
		#if defined YSI_LOCK_MODE
			YSI_gLockData[0] += 1;
			for (new i = 0; i != 2; ++i)
			{
				YSI_gLockData[0] = YSI_gLockData[0] * 9 + 2;
			}
			YSI_gLockData[0] -= 1;
			YSI_gLockData[3] = YSI_gLockData[0];
			YSI_gLockData[0] -= 1;
			YSI_gLockData[2] = YSI_gLockData[0] + 11;
			YSI_gLockData[0] -= 1;
			YSI_gLockData[1] = YSI_gLockData[0] + 7;
		#endif
		YVers_PrintHeader();
		//YSI_Print(" |                                      | ");
		//YSI_Print(" |  Checking the latest YSI version..   | ");
		//YSI_Print(" |                                        | ");
		//YSI_Print(" ========================================== ");
		// Call my server to check the current public YSI version.  v is the
		// current version and c is the version of data response which this code
		// can parse.  Note that the response data SHOULD be backward compatible
		// , but may not always be - hence the accept parameter.  This will
		// never send any data except the current version for targeted replies
		// (e.g. to ignore minor updates which aren't critical).  It MAY in the
		// future send what libraries are in use so that it only tells you to
		// upgrade if the libraries you are using have changed, but that will
		// take more work and I'm not going to do that for now (I'm not entirely
		// sure exactly how to do it (though I have an idea - note to self:
		// chain callbacks from repeated inclusions of this file in the same way
		// as ALS then call them BEFORE sending the HTTP)).  Note that due to
		// the way the internet works the server will know the IP of the server
		// which sent the request, but the ENTIRE current contents of the remote
		// page are (note: I won't update this comment every time the version
		// updates, but that's the gist of it):
		//  
		//  1
		//  1.01.0000
		//  
		// This remote script has now been updated to include changelog
		// information and keeps a record of what IPs are connecting.
		//HTTP(0, HTTP_GET, "version.ysi.tl/index.php?c=" #YSI_VERSION_RESPO "&v=" YSI_VERSION, "", "YVers_Callback");
		return 1;
	}
	
	/*---------------------------------------------------------------------*//*+
	 *
	 * <param name="	index">Not used.</param>
	 * <param name="	code">Response code from the server.</param>
	 * <param name="	data[]">HTTP data sent from the server.</param>
	 * <remarks>
	 *  This is called when my server responds to the HTTP request sent above
	 *  (or when it doesn't).  This prints information on the current and any
	 *  future versions of YSI.  Note that it only does a strcmp to determine if
	 *  the version is newer - people can't have versions newer than the latest,
	 *  onlyolder or equal (unless they play with the version numbers, but then
	 *  that's their own fault).
	 * </remarks>
	 *//*--------------------------------------------------------------------**/
	
	public YVers_Callback(index, code, data[])
	{
		if (code == 200)
		{
			// Got the remote page.
			// The first line is the version data version.  This should be
			// forward compatible, so new data is always added to the end of the
			// file. Skip the first line - contains the response version.
			new
				pos = strfind(data, "\n") + 1;
			if (strcmp(data[pos], YSI_VERSION, false, 9))
			{
				//data[pos + 9] = '\0';
				YSI_Print(" ");
				YSI_Print(" ========================================== ");
				YSI_Print(" |                                        | ");
				YSI_PrintF(" |  A new version (v%.9s) of YSI is  | ", data[pos]);
				YSI_Print(" |            available from:             | ");
				YSI_Print(" |                                        | ");
				YSI_Print(" |     www.y-less.com/YSI/YSI_1.0.zip     | ");
				if (data[0] == '2')
				{
					YSI_Print(" |                                        | ");
					YSI_Print(" | Changelog:                             | ");
					// Print the changelog.
					new
						last = pos + 13;
					for ( ; ; )
					{
						pos = strfind(data[last], "\n", false);
						if (pos == -1)
						{
							// To break out in the middle of a loop.
							break;
						}
						pos += last;
						data[pos - 1] = '\0';
						YSI_PrintF(" | %38s | ", data[last]);
						last = pos + 1;
					}
				}
				YSI_Print(" |                                        | ");
				YSI_Print(" ========================================== ");
				YSI_Print(" ");
			}
		}
	}
	
#endif

