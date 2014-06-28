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

#ifndef _MIKELEPAGE_RULESET_HPP_
#define _MIKELEPAGE_RULESET_HPP_

#include "rule_set_base.hpp"
#include <cyvmath/match.hpp>

#include <fea/rendering/quad.hpp>
#include <fea/rendering/renderer2d.hpp>
#include <cyvmath/mikelepage/piece.hpp>
#include "hexagon_board.hpp"
#include "local_player.hpp"
#include "rendered_piece.hpp"

namespace mikelepage
{
	/** This rule set was created by Michael Le Page (http://www.mikelepage.com/)

		See http://asoiaf.westeros.org/index.php/topic/58545-complete-cyvasse-rules/
	 */
	class MikelepageRuleSet : public RuleSetBase, protected cyvmath::Match
	{
		public:
			typedef HexagonBoard<6> Board;

		private:
			Board _board;

			std::shared_ptr<LocalPlayer> _self;

			// for rendering
			RenderedPieceVec _allPieces;

			fea::Texture _buttonSetupDoneTexture;
			fea::Quad _buttonSetupDone;

		public:
			MikelepageRuleSet(fea::Renderer2D&, cyvmath::PlayersColor firstPlayer);
			~MikelepageRuleSet() = default;

			// non-copyable
			MikelepageRuleSet(const MikelepageRuleSet&) = delete;
			const MikelepageRuleSet& operator= (const MikelepageRuleSet&) = delete;

			void tick() final override;

			void processEvent(fea::Event&) final override;

			void placePiecesSetup();
			void exitSetup();
	};
}

#endif // _MIKELEPAGE_RULESET_HPP_