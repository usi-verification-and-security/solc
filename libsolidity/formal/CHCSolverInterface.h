/*
	This file is part of solidity.

	solidity is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	solidity is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with solidity.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 * Interface for constrained Horn solvers.
 */

#pragma once

#include <libsolidity/formal/SolverInterface.h>

#include <map>
#include <vector>

namespace solidity::frontend::smt
{

class CHCSolverInterface
{
public:
	virtual ~CHCSolverInterface() = default;

	virtual void declareVariable(std::string const& _name, SortPointer const& _sort) = 0;

	/// Takes a function declaration as a relation.
	virtual void registerRelation(Expression const& _expr) = 0;

	/// Takes an implication and adds as rule.
	/// Needs to bound all vars as universally quantified.
	virtual void addRule(Expression const& _expr, std::string const& _name) = 0;

	/// Each node represents a predicate, where `first` is the
	/// predicate's name and `second` is the list of arguments.
	using Node = std::string;
	using Graph = std::map<Node, std::pair<std::vector<std::string>, std::vector<Node>>>;
	/// Takes a function application and checks
	/// for reachability.
	virtual std::pair<CheckResult, Graph> query(
		Expression const& _expr
	) = 0;
};

}
