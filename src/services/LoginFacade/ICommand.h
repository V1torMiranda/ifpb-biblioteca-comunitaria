//
// Created by vitor on 30/07/2025.
//

#ifndef BIBLIOTECA_COMUNITARIA_ICOMMAND_H
#define BIBLIOTECA_COMUNITARIA_ICOMMAND_H

#endif //BIBLIOTECA_COMUNITARIA_ICOMMAND_H

// ICommand.hpp
#ifndef ICOMMAND_HPP
#define ICOMMAND_HPP

class ICommand {
public:
    virtual ~ICommand() = default;
    virtual void execute() = 0;
};

#endif
