class HideKeys_FromServer
{
	public: void CL_CreateMove() // METHOD IS NOT UNDETECT, SO YOU MAY GET BANNED BY ANTICHEAT ON SOME SERVERS!
	{
		/*Call this method only in the "Cl_CreateMove" method, it is usually in client.cpp, otherwise it will crash

		Hiding keys will not work for rage strafe in different directions(as you will be jerked from one side to the other) and will not work on ladders
		(you will just freeze), you can also add your own conditions */
		if (g_Local.m_bIsDead || state.rage_strafe_active && cvar.movement.strafe_invisible_direction == 4 || g_Local.m_bIsOnLadder)
			return;

		usercmd_s* pCmd = cmd::get();

		switch (cvar.movement.client_hidekeys_type) // case 0: - no hide pressed keys (disable aka return)
		{
			case 1: pCmd->buttons &= ~IN_FORWARD;   break;  // Hide keys "W"
			case 2: pCmd->buttons &= ~IN_BACK;      break;  // Hide keys "S"
			case 3: pCmd->buttons &= ~IN_MOVELEFT;  break;  // Hide keys "A"
			case 4: pCmd->buttons &= ~IN_MOVERIGHT; break;  // Hide keys "D"

			case 5: // Hide keys "W & S"
			{
				pCmd->buttons &= ~IN_FORWARD;
				pCmd->buttons &= ~IN_BACK;
			}
			break;

			case 6: // Hide keys "A & D"
			{
				pCmd->buttons &= ~IN_MOVELEFT;
				pCmd->buttons &= ~IN_MOVERIGHT;
			}
			break;

			case 7: // Hide keys "W & A"
			{
				pCmd->buttons &= ~IN_FORWARD;
				pCmd->buttons &= ~IN_MOVERIGHT;
			}
			break;

			case 8: // Hide keys "W & D"
			{
				pCmd->buttons &= ~IN_FORWARD;
				pCmd->buttons &= ~IN_MOVERIGHT;
			}
			break;

			case 9: // Hide keys "S & A"
			{
				pCmd->buttons &= ~IN_BACK;
				pCmd->buttons &= ~IN_MOVELEFT;
			}
			break;

			case 10: // Hide keys "S & D"
			{
				pCmd->buttons &= ~IN_BACK;
				pCmd->buttons &= ~IN_MOVERIGHT;
			}
			break;

			case 11: // Hide keys "All"
			{
				pCmd->buttons &= ~IN_FORWARD;
				pCmd->buttons &= ~IN_BACK;
				pCmd->buttons &= ~IN_MOVELEFT;
				pCmd->buttons &= ~IN_MOVERIGHT;
			}
			break;
		}
	}
};
