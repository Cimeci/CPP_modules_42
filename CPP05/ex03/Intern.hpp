/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:33:15 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/09 16:19:13 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern{
	public:
		// CANONICAL FORM //
		Intern();
		Intern(Intern const &cp);
		Intern &operator=(Intern const &op);
		~Intern();
		// CANONICAL FORM //

		AForm *makeForm(const std::string &FormName, const std::string &FormTarget);
};