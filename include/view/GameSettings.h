#ifndef GAMESETTINGS_H
#define GAMESETTINGS_H


class GameSettings
{
    public:
        GameSettings();
        virtual ~GameSettings();
        GameSettings(const GameSettings& other);
        GameSettings& operator=(const GameSettings& other);

    protected:

    private:
};

#endif // GAMESETTINGS_H
