//------------------------------------------------------------------------------
//
//
//
//
//------------------------------------------------------------------------------
/*!
 * \file
 * \brief
 * \copyright
 * \author
 * \date
 */

#ifndef     VIEWER_H
#define     VIEWER_H

#include    <osgViewer/Viewer>

#include    "settings.h"
#include    "command-line-parser.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class RouteViewer
{
public:

    /// Constructor
    RouteViewer(int argc, char *argv[]);

    /// Destructor
    virtual ~RouteViewer();

    /// Get ready state
    bool isReady() const;

    /// Start client
    int run();

protected:

    /// Viewer ready flag
    bool                        is_ready;
    /// Viewer settings
    settings_t                  settings;

    /// OSG viewer object
    osgViewer::Viewer           viewer;

    /// OSG scene root node
    osg::ref_ptr<osg::Group>    root;

    /// Initialization
    bool init(int argc, char *argv[]);   

    /// Load settings from config
    settings_t loadSettings(const std::string &cfg_path) const;

    /// Override settings from command line
    void overrideSettingsByCommandLine(const cmd_line_t &cmd_line,
                                       settings_t settings);

    /// Load route form directory
    bool loadRoute(const std::string &routeDir);

    /// Init common graphical engine settings
    bool initEngineSettings(osg::Group *root);

    /// Init display
    bool initDisplay(osgViewer::Viewer *viewer, const settings_t &settings);

    /// Init motion blur
    bool initMotionBlurEffect(osgViewer::Viewer *viewer, const settings_t &settings);
};

#endif // VIEWER_H
