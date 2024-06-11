#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource()
{
    for (int i = 0; i < 4; ++i) {
        _source[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other) : IMateriaSource(other)
{
    for (int i = 0; i < 4; ++i) {
        if (other._source[i]) {
            _source[i] = other._source[i]->clone();
        } else {
            _source[i] = NULL;
        }
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        IMateriaSource::operator=(other);
        for (int i = 0; i < 4; ++i) {
            if (_source[i]) {
                delete _source[i];
            }
            if (other._source[i]) {
                _source[i] = other._source[i]->clone();
            } else {
                _source[i] = NULL;
            }
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        if (_source[i]) {
            delete _source[i];
        }
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; ++i) {
        if (!_source[i]) {
            _source[i] = m;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const& type) {
    for (int i = 0; i < 4; ++i) {
        if (_source[i] && _source[i]->getType() == type) {
            return _source[i]->clone();
        }
    }
    return NULL;
}