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

#ifndef _MIKELEPAGE_RENDERED_PIECE_HPP_
#define _MIKELEPAGE_RENDERED_PIECE_HPP_

#include <cyvmath/mikelepage/piece.hpp>
#include <fea/rendering/quad.hpp>

#include "hexagon_board.hpp"

namespace mikelepage
{
	class RenderedPiece : public cyvmath::mikelepage::Piece, public fea::Quad
	{
		public:
			typedef HexagonBoard<6> Board;

		private:
			Board& _board;

		public:
			RenderedPiece(cyvmath::PieceType, dc::unique_ptr<cyvmath::mikelepage::Coordinate>&&,
			              cyvmath::PlayersColor, PieceMap&, Board&);

			bool moveTo(const cyvmath::CoordinateDcUqP&, bool checkMoveValidity) override;
	};

	typedef std::vector<std::shared_ptr<RenderedPiece>> RenderedPieceVec;
}

#endif // _MIKELEPAGE_RENDERED_PIECE_HPP_