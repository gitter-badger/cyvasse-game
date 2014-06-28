/* Copyright 2014 Jonas Platte
*
* This file is part of Cyvasse Online.
*
* Cyvasse Online is free software: you can redistribute it and/or modify it under the
* terms of the GNU Affero General Public License as published by the Free Software Foundation,
* either version 3 of the License, or (at your option) any later version.
*
* Cyvasse Online is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
* PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
*
* You should have received a copy of the GNU Affero General Public License along with this program.
* If not, see <http://www.gnu.org/licenses/>.
*/

#include <functional>
#include <emscripten.h>
#include <jsoncpp/json/reader.h>

class WebsocketImpl
{
	public:
		// TODO
};

extern "C"
{
	void game_handlemessage(const char* msgData)
	{
		if(!CyvasseWSClient::instance())
		{
			EM_ASM(
				throw new Error('game_handlemessage called without CyvasseWSClient being initialized!\n');
			);
		}

		if(CyvasseWSClient::instance()->handleMessage) // if std::function object holds a callable
		{
			Json::Value val;
			if((Json::Reader()).parse(std::string(msgData), val, false))
				CyvasseWSClient::instance()->handleMessage(val);
		}
	}
}