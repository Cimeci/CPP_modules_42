/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:43:00 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/15 10:49:34 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "AForm.hpp"
#include <fstream>

class PresidentialPardonForm: public AForm{

	private:
		const std::string target;

	public:
		// CANONICAL FORM //
		PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const &cp);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &op);
		~PresidentialPardonForm();
		// CANONICAL FORM //

		PresidentialPardonForm(const std::string target);

		void executeAction(void) const;

		std::string getTarget(void) const;
};
std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& b);
