//#line 2 "/opt/ros/kinetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"
// *********************************************************
//
// File autogenerated for the depth_sensor_pose package
// by the dynamic_reconfigure package.
// Please do not edit.
//
// ********************************************************/

#ifndef __depth_sensor_pose__DEPTHSENSORPOSECONFIG_H__
#define __depth_sensor_pose__DEPTHSENSORPOSECONFIG_H__

#include <dynamic_reconfigure/config_tools.h>
#include <limits>
#include <ros/node_handle.h>
#include <dynamic_reconfigure/ConfigDescription.h>
#include <dynamic_reconfigure/ParamDescription.h>
#include <dynamic_reconfigure/Group.h>
#include <dynamic_reconfigure/config_init_mutex.h>
#include <boost/any.hpp>

namespace depth_sensor_pose
{
  class DepthSensorPoseConfigStatics;

  class DepthSensorPoseConfig
  {
  public:
    class AbstractParamDescription : public dynamic_reconfigure::ParamDescription
    {
    public:
      AbstractParamDescription(std::string n, std::string t, uint32_t l,
          std::string d, std::string e)
      {
        name = n;
        type = t;
        level = l;
        description = d;
        edit_method = e;
      }

      virtual void clamp(DepthSensorPoseConfig &config, const DepthSensorPoseConfig &max, const DepthSensorPoseConfig &min) const = 0;
      virtual void calcLevel(uint32_t &level, const DepthSensorPoseConfig &config1, const DepthSensorPoseConfig &config2) const = 0;
      virtual void fromServer(const ros::NodeHandle &nh, DepthSensorPoseConfig &config) const = 0;
      virtual void toServer(const ros::NodeHandle &nh, const DepthSensorPoseConfig &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, DepthSensorPoseConfig &config) const = 0;
      virtual void toMessage(dynamic_reconfigure::Config &msg, const DepthSensorPoseConfig &config) const = 0;
      virtual void getValue(const DepthSensorPoseConfig &config, boost::any &val) const = 0;
    };

    typedef boost::shared_ptr<AbstractParamDescription> AbstractParamDescriptionPtr;
    typedef boost::shared_ptr<const AbstractParamDescription> AbstractParamDescriptionConstPtr;

    template <class T>
    class ParamDescription : public AbstractParamDescription
    {
    public:
      ParamDescription(std::string a_name, std::string a_type, uint32_t a_level,
          std::string a_description, std::string a_edit_method, T DepthSensorPoseConfig::* a_f) :
        AbstractParamDescription(a_name, a_type, a_level, a_description, a_edit_method),
        field(a_f)
      {}

      T (DepthSensorPoseConfig::* field);

      virtual void clamp(DepthSensorPoseConfig &config, const DepthSensorPoseConfig &max, const DepthSensorPoseConfig &min) const
      {
        if (config.*field > max.*field)
          config.*field = max.*field;

        if (config.*field < min.*field)
          config.*field = min.*field;
      }

      virtual void calcLevel(uint32_t &comb_level, const DepthSensorPoseConfig &config1, const DepthSensorPoseConfig &config2) const
      {
        if (config1.*field != config2.*field)
          comb_level |= level;
      }

      virtual void fromServer(const ros::NodeHandle &nh, DepthSensorPoseConfig &config) const
      {
        nh.getParam(name, config.*field);
      }

      virtual void toServer(const ros::NodeHandle &nh, const DepthSensorPoseConfig &config) const
      {
        nh.setParam(name, config.*field);
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, DepthSensorPoseConfig &config) const
      {
        return dynamic_reconfigure::ConfigTools::getParameter(msg, name, config.*field);
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const DepthSensorPoseConfig &config) const
      {
        dynamic_reconfigure::ConfigTools::appendParameter(msg, name, config.*field);
      }

      virtual void getValue(const DepthSensorPoseConfig &config, boost::any &val) const
      {
        val = config.*field;
      }
    };

    class AbstractGroupDescription : public dynamic_reconfigure::Group
    {
      public:
      AbstractGroupDescription(std::string n, std::string t, int p, int i, bool s)
      {
        name = n;
        type = t;
        parent = p;
        state = s;
        id = i;
      }

      std::vector<AbstractParamDescriptionConstPtr> abstract_parameters;
      bool state;

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &config) const =0;
      virtual void updateParams(boost::any &cfg, DepthSensorPoseConfig &top) const= 0;
      virtual void setInitialState(boost::any &cfg) const = 0;


      void convertParams()
      {
        for(std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = abstract_parameters.begin(); i != abstract_parameters.end(); ++i)
        {
          parameters.push_back(dynamic_reconfigure::ParamDescription(**i));
        }
      }
    };

    typedef boost::shared_ptr<AbstractGroupDescription> AbstractGroupDescriptionPtr;
    typedef boost::shared_ptr<const AbstractGroupDescription> AbstractGroupDescriptionConstPtr;

    template<class T, class PT>
    class GroupDescription : public AbstractGroupDescription
    {
    public:
      GroupDescription(std::string a_name, std::string a_type, int a_parent, int a_id, bool a_s, T PT::* a_f) : AbstractGroupDescription(a_name, a_type, a_parent, a_id, a_s), field(a_f)
      {
      }

      GroupDescription(const GroupDescription<T, PT>& g): AbstractGroupDescription(g.name, g.type, g.parent, g.id, g.state), field(g.field), groups(g.groups)
      {
        parameters = g.parameters;
        abstract_parameters = g.abstract_parameters;
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        if(!dynamic_reconfigure::ConfigTools::getGroupState(msg, name, (*config).*field))
          return false;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          if(!(*i)->fromMessage(msg, n))
            return false;
        }

        return true;
      }

      virtual void setInitialState(boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        T* group = &((*config).*field);
        group->state = state;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = boost::any(&((*config).*field));
          (*i)->setInitialState(n);
        }

      }

      virtual void updateParams(boost::any &cfg, DepthSensorPoseConfig &top) const
      {
        PT* config = boost::any_cast<PT*>(cfg);

        T* f = &((*config).*field);
        f->setParams(top, abstract_parameters);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          (*i)->updateParams(n, top);
        }
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &cfg) const
      {
        const PT config = boost::any_cast<PT>(cfg);
        dynamic_reconfigure::ConfigTools::appendGroup<T>(msg, name, id, parent, config.*field);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          (*i)->toMessage(msg, config.*field);
        }
      }

      T (PT::* field);
      std::vector<DepthSensorPoseConfig::AbstractGroupDescriptionConstPtr> groups;
    };

class DEFAULT
{
  public:
    DEFAULT()
    {
      state = true;
      name = "Default";
    }

    void setParams(DepthSensorPoseConfig &config, const std::vector<AbstractParamDescriptionConstPtr> params)
    {
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator _i = params.begin(); _i != params.end(); ++_i)
      {
        boost::any val;
        (*_i)->getValue(config, val);

        if("rate"==(*_i)->name){rate = boost::any_cast<double>(val);}
        if("range_min"==(*_i)->name){range_min = boost::any_cast<double>(val);}
        if("range_max"==(*_i)->name){range_max = boost::any_cast<double>(val);}
        if("mount_height_min"==(*_i)->name){mount_height_min = boost::any_cast<double>(val);}
        if("mount_height_max"==(*_i)->name){mount_height_max = boost::any_cast<double>(val);}
        if("tilt_angle_min"==(*_i)->name){tilt_angle_min = boost::any_cast<double>(val);}
        if("tilt_angle_max"==(*_i)->name){tilt_angle_max = boost::any_cast<double>(val);}
        if("publish_depth"==(*_i)->name){publish_depth = boost::any_cast<bool>(val);}
        if("cam_model_update"==(*_i)->name){cam_model_update = boost::any_cast<bool>(val);}
        if("used_depth_height"==(*_i)->name){used_depth_height = boost::any_cast<int>(val);}
        if("depth_img_step_row"==(*_i)->name){depth_img_step_row = boost::any_cast<int>(val);}
        if("depth_img_step_col"==(*_i)->name){depth_img_step_col = boost::any_cast<int>(val);}
        if("ground_max_points"==(*_i)->name){ground_max_points = boost::any_cast<int>(val);}
        if("ransac_max_iter"==(*_i)->name){ransac_max_iter = boost::any_cast<int>(val);}
        if("ransac_dist_thresh"==(*_i)->name){ransac_dist_thresh = boost::any_cast<double>(val);}
      }
    }

    double rate;
double range_min;
double range_max;
double mount_height_min;
double mount_height_max;
double tilt_angle_min;
double tilt_angle_max;
bool publish_depth;
bool cam_model_update;
int used_depth_height;
int depth_img_step_row;
int depth_img_step_col;
int ground_max_points;
int ransac_max_iter;
double ransac_dist_thresh;

    bool state;
    std::string name;

    
}groups;



//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double rate;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double range_min;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double range_max;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double mount_height_min;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double mount_height_max;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double tilt_angle_min;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double tilt_angle_max;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool publish_depth;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool cam_model_update;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int used_depth_height;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int depth_img_step_row;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int depth_img_step_col;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int ground_max_points;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int ransac_max_iter;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double ransac_dist_thresh;
//#line 218 "/opt/ros/kinetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

    bool __fromMessage__(dynamic_reconfigure::Config &msg)
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();

      int count = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        if ((*i)->fromMessage(msg, *this))
          count++;

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i ++)
      {
        if ((*i)->id == 0)
        {
          boost::any n = boost::any(this);
          (*i)->updateParams(n, *this);
          (*i)->fromMessage(msg, n);
        }
      }

      if (count != dynamic_reconfigure::ConfigTools::size(msg))
      {
        ROS_ERROR("DepthSensorPoseConfig::__fromMessage__ called with an unexpected parameter.");
        ROS_ERROR("Booleans:");
        for (unsigned int i = 0; i < msg.bools.size(); i++)
          ROS_ERROR("  %s", msg.bools[i].name.c_str());
        ROS_ERROR("Integers:");
        for (unsigned int i = 0; i < msg.ints.size(); i++)
          ROS_ERROR("  %s", msg.ints[i].name.c_str());
        ROS_ERROR("Doubles:");
        for (unsigned int i = 0; i < msg.doubles.size(); i++)
          ROS_ERROR("  %s", msg.doubles[i].name.c_str());
        ROS_ERROR("Strings:");
        for (unsigned int i = 0; i < msg.strs.size(); i++)
          ROS_ERROR("  %s", msg.strs[i].name.c_str());
        // @todo Check that there are no duplicates. Make this error more
        // explicit.
        return false;
      }
      return true;
    }

    // This version of __toMessage__ is used during initialization of
    // statics when __getParamDescriptions__ can't be called yet.
    void __toMessage__(dynamic_reconfigure::Config &msg, const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__, const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__) const
    {
      dynamic_reconfigure::ConfigTools::clear(msg);
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toMessage(msg, *this);

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        if((*i)->id == 0)
        {
          (*i)->toMessage(msg, *this);
        }
      }
    }

    void __toMessage__(dynamic_reconfigure::Config &msg) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      __toMessage__(msg, __param_descriptions__, __group_descriptions__);
    }

    void __toServer__(const ros::NodeHandle &nh) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toServer(nh, *this);
    }

    void __fromServer__(const ros::NodeHandle &nh)
    {
      static bool setup=false;

      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->fromServer(nh, *this);

      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i++){
        if (!setup && (*i)->id == 0) {
          setup = true;
          boost::any n = boost::any(this);
          (*i)->setInitialState(n);
        }
      }
    }

    void __clamp__()
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const DepthSensorPoseConfig &__max__ = __getMax__();
      const DepthSensorPoseConfig &__min__ = __getMin__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->clamp(*this, __max__, __min__);
    }

    uint32_t __level__(const DepthSensorPoseConfig &config) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      uint32_t level = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->calcLevel(level, config, *this);
      return level;
    }

    static const dynamic_reconfigure::ConfigDescription &__getDescriptionMessage__();
    static const DepthSensorPoseConfig &__getDefault__();
    static const DepthSensorPoseConfig &__getMax__();
    static const DepthSensorPoseConfig &__getMin__();
    static const std::vector<AbstractParamDescriptionConstPtr> &__getParamDescriptions__();
    static const std::vector<AbstractGroupDescriptionConstPtr> &__getGroupDescriptions__();

  private:
    static const DepthSensorPoseConfigStatics *__get_statics__();
  };

  template <> // Max and min are ignored for strings.
  inline void DepthSensorPoseConfig::ParamDescription<std::string>::clamp(DepthSensorPoseConfig &config, const DepthSensorPoseConfig &max, const DepthSensorPoseConfig &min) const
  {
    (void) config;
    (void) min;
    (void) max;
    return;
  }

  class DepthSensorPoseConfigStatics
  {
    friend class DepthSensorPoseConfig;

    DepthSensorPoseConfigStatics()
    {
DepthSensorPoseConfig::GroupDescription<DepthSensorPoseConfig::DEFAULT, DepthSensorPoseConfig> Default("Default", "", 0, 0, true, &DepthSensorPoseConfig::groups);
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.rate = 0.1;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.rate = 30.0;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.rate = 10.0;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(DepthSensorPoseConfig::AbstractParamDescriptionConstPtr(new DepthSensorPoseConfig::ParamDescription<double>("rate", "double", 0, "Data processing frequency  (Hz).", "", &DepthSensorPoseConfig::rate)));
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(DepthSensorPoseConfig::AbstractParamDescriptionConstPtr(new DepthSensorPoseConfig::ParamDescription<double>("rate", "double", 0, "Data processing frequency  (Hz).", "", &DepthSensorPoseConfig::rate)));
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.range_min = 0.2;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.range_min = 10.0;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.range_min = 0.5;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(DepthSensorPoseConfig::AbstractParamDescriptionConstPtr(new DepthSensorPoseConfig::ParamDescription<double>("range_min", "double", 0, "Minimum sensor range (in meters).", "", &DepthSensorPoseConfig::range_min)));
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(DepthSensorPoseConfig::AbstractParamDescriptionConstPtr(new DepthSensorPoseConfig::ParamDescription<double>("range_min", "double", 0, "Minimum sensor range (in meters).", "", &DepthSensorPoseConfig::range_min)));
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.range_max = 0.5;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.range_max = 20.0;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.range_max = 5.0;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(DepthSensorPoseConfig::AbstractParamDescriptionConstPtr(new DepthSensorPoseConfig::ParamDescription<double>("range_max", "double", 0, "Maximum sensor range (in meters).", "", &DepthSensorPoseConfig::range_max)));
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(DepthSensorPoseConfig::AbstractParamDescriptionConstPtr(new DepthSensorPoseConfig::ParamDescription<double>("range_max", "double", 0, "Maximum sensor range (in meters).", "", &DepthSensorPoseConfig::range_max)));
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.mount_height_min = 0.0;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.mount_height_min = 10.0;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.mount_height_min = 1.4;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(DepthSensorPoseConfig::AbstractParamDescriptionConstPtr(new DepthSensorPoseConfig::ParamDescription<double>("mount_height_min", "double", 0, "Height of kinect mount (m).", "", &DepthSensorPoseConfig::mount_height_min)));
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(DepthSensorPoseConfig::AbstractParamDescriptionConstPtr(new DepthSensorPoseConfig::ParamDescription<double>("mount_height_min", "double", 0, "Height of kinect mount (m).", "", &DepthSensorPoseConfig::mount_height_min)));
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.mount_height_max = 0.0;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.mount_height_max = 10.0;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.mount_height_max = 1.6;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(DepthSensorPoseConfig::AbstractParamDescriptionConstPtr(new DepthSensorPoseConfig::ParamDescription<double>("mount_height_max", "double", 0, "Height of kinect mount (m).", "", &DepthSensorPoseConfig::mount_height_max)));
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(DepthSensorPoseConfig::AbstractParamDescriptionConstPtr(new DepthSensorPoseConfig::ParamDescription<double>("mount_height_max", "double", 0, "Height of kinect mount (m).", "", &DepthSensorPoseConfig::mount_height_max)));
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.tilt_angle_min = -30.0;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.tilt_angle_min = 30.0;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.tilt_angle_min = 20.0;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(DepthSensorPoseConfig::AbstractParamDescriptionConstPtr(new DepthSensorPoseConfig::ParamDescription<double>("tilt_angle_min", "double", 0, "Sensor tilt angle (degrees).", "", &DepthSensorPoseConfig::tilt_angle_min)));
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(DepthSensorPoseConfig::AbstractParamDescriptionConstPtr(new DepthSensorPoseConfig::ParamDescription<double>("tilt_angle_min", "double", 0, "Sensor tilt angle (degrees).", "", &DepthSensorPoseConfig::tilt_angle_min)));
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.tilt_angle_max = -30.0;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.tilt_angle_max = 30.0;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.tilt_angle_max = 10.0;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(DepthSensorPoseConfig::AbstractParamDescriptionConstPtr(new DepthSensorPoseConfig::ParamDescription<double>("tilt_angle_max", "double", 0, "Sensor tilt angle (degrees).", "", &DepthSensorPoseConfig::tilt_angle_max)));
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(DepthSensorPoseConfig::AbstractParamDescriptionConstPtr(new DepthSensorPoseConfig::ParamDescription<double>("tilt_angle_max", "double", 0, "Sensor tilt angle (degrees).", "", &DepthSensorPoseConfig::tilt_angle_max)));
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.publish_depth = 0;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.publish_depth = 1;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.publish_depth = 0;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(DepthSensorPoseConfig::AbstractParamDescriptionConstPtr(new DepthSensorPoseConfig::ParamDescription<bool>("publish_depth", "bool", 0, "Determines if depth should be republished.", "", &DepthSensorPoseConfig::publish_depth)));
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(DepthSensorPoseConfig::AbstractParamDescriptionConstPtr(new DepthSensorPoseConfig::ParamDescription<bool>("publish_depth", "bool", 0, "Determines if depth should be republished.", "", &DepthSensorPoseConfig::publish_depth)));
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.cam_model_update = 0;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.cam_model_update = 1;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.cam_model_update = 1;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(DepthSensorPoseConfig::AbstractParamDescriptionConstPtr(new DepthSensorPoseConfig::ParamDescription<bool>("cam_model_update", "bool", 0, "If continously camera data update.", "", &DepthSensorPoseConfig::cam_model_update)));
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(DepthSensorPoseConfig::AbstractParamDescriptionConstPtr(new DepthSensorPoseConfig::ParamDescription<bool>("cam_model_update", "bool", 0, "If continously camera data update.", "", &DepthSensorPoseConfig::cam_model_update)));
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.used_depth_height = 1;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.used_depth_height = 1000;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.used_depth_height = 400;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(DepthSensorPoseConfig::AbstractParamDescriptionConstPtr(new DepthSensorPoseConfig::ParamDescription<int>("used_depth_height", "int", 0, "Used depth height from img bottom (px).", "", &DepthSensorPoseConfig::used_depth_height)));
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(DepthSensorPoseConfig::AbstractParamDescriptionConstPtr(new DepthSensorPoseConfig::ParamDescription<int>("used_depth_height", "int", 0, "Used depth height from img bottom (px).", "", &DepthSensorPoseConfig::used_depth_height)));
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.depth_img_step_row = 1;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.depth_img_step_row = 100;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.depth_img_step_row = 8;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(DepthSensorPoseConfig::AbstractParamDescriptionConstPtr(new DepthSensorPoseConfig::ParamDescription<int>("depth_img_step_row", "int", 0, "Rows step in depth processing (px).", "", &DepthSensorPoseConfig::depth_img_step_row)));
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(DepthSensorPoseConfig::AbstractParamDescriptionConstPtr(new DepthSensorPoseConfig::ParamDescription<int>("depth_img_step_row", "int", 0, "Rows step in depth processing (px).", "", &DepthSensorPoseConfig::depth_img_step_row)));
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.depth_img_step_col = 1;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.depth_img_step_col = 100;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.depth_img_step_col = 8;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(DepthSensorPoseConfig::AbstractParamDescriptionConstPtr(new DepthSensorPoseConfig::ParamDescription<int>("depth_img_step_col", "int", 0, "Columns step in depth processing (px).", "", &DepthSensorPoseConfig::depth_img_step_col)));
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(DepthSensorPoseConfig::AbstractParamDescriptionConstPtr(new DepthSensorPoseConfig::ParamDescription<int>("depth_img_step_col", "int", 0, "Columns step in depth processing (px).", "", &DepthSensorPoseConfig::depth_img_step_col)));
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.ground_max_points = 3;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.ground_max_points = 20000;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.ground_max_points = 1000;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(DepthSensorPoseConfig::AbstractParamDescriptionConstPtr(new DepthSensorPoseConfig::ParamDescription<int>("ground_max_points", "int", 0, "Max ground points in selection stage.", "", &DepthSensorPoseConfig::ground_max_points)));
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(DepthSensorPoseConfig::AbstractParamDescriptionConstPtr(new DepthSensorPoseConfig::ParamDescription<int>("ground_max_points", "int", 0, "Max ground points in selection stage.", "", &DepthSensorPoseConfig::ground_max_points)));
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.ransac_max_iter = 10;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.ransac_max_iter = 10000;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.ransac_max_iter = 1000;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(DepthSensorPoseConfig::AbstractParamDescriptionConstPtr(new DepthSensorPoseConfig::ParamDescription<int>("ransac_max_iter", "int", 0, "Max number of RANSAC iterations.", "", &DepthSensorPoseConfig::ransac_max_iter)));
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(DepthSensorPoseConfig::AbstractParamDescriptionConstPtr(new DepthSensorPoseConfig::ParamDescription<int>("ransac_max_iter", "int", 0, "Max number of RANSAC iterations.", "", &DepthSensorPoseConfig::ransac_max_iter)));
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.ransac_dist_thresh = 0.0001;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.ransac_dist_thresh = 1.0;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.ransac_dist_thresh = 0.01;
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(DepthSensorPoseConfig::AbstractParamDescriptionConstPtr(new DepthSensorPoseConfig::ParamDescription<double>("ransac_dist_thresh", "double", 0, "RANSAC distance threshold.", "", &DepthSensorPoseConfig::ransac_dist_thresh)));
//#line 292 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(DepthSensorPoseConfig::AbstractParamDescriptionConstPtr(new DepthSensorPoseConfig::ParamDescription<double>("ransac_dist_thresh", "double", 0, "RANSAC distance threshold.", "", &DepthSensorPoseConfig::ransac_dist_thresh)));
//#line 245 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.convertParams();
//#line 245 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __group_descriptions__.push_back(DepthSensorPoseConfig::AbstractGroupDescriptionConstPtr(new DepthSensorPoseConfig::GroupDescription<DepthSensorPoseConfig::DEFAULT, DepthSensorPoseConfig>(Default)));
//#line 356 "/opt/ros/kinetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

      for (std::vector<DepthSensorPoseConfig::AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        __description_message__.groups.push_back(**i);
      }
      __max__.__toMessage__(__description_message__.max, __param_descriptions__, __group_descriptions__);
      __min__.__toMessage__(__description_message__.min, __param_descriptions__, __group_descriptions__);
      __default__.__toMessage__(__description_message__.dflt, __param_descriptions__, __group_descriptions__);
    }
    std::vector<DepthSensorPoseConfig::AbstractParamDescriptionConstPtr> __param_descriptions__;
    std::vector<DepthSensorPoseConfig::AbstractGroupDescriptionConstPtr> __group_descriptions__;
    DepthSensorPoseConfig __max__;
    DepthSensorPoseConfig __min__;
    DepthSensorPoseConfig __default__;
    dynamic_reconfigure::ConfigDescription __description_message__;

    static const DepthSensorPoseConfigStatics *get_instance()
    {
      // Split this off in a separate function because I know that
      // instance will get initialized the first time get_instance is
      // called, and I am guaranteeing that get_instance gets called at
      // most once.
      static DepthSensorPoseConfigStatics instance;
      return &instance;
    }
  };

  inline const dynamic_reconfigure::ConfigDescription &DepthSensorPoseConfig::__getDescriptionMessage__()
  {
    return __get_statics__()->__description_message__;
  }

  inline const DepthSensorPoseConfig &DepthSensorPoseConfig::__getDefault__()
  {
    return __get_statics__()->__default__;
  }

  inline const DepthSensorPoseConfig &DepthSensorPoseConfig::__getMax__()
  {
    return __get_statics__()->__max__;
  }

  inline const DepthSensorPoseConfig &DepthSensorPoseConfig::__getMin__()
  {
    return __get_statics__()->__min__;
  }

  inline const std::vector<DepthSensorPoseConfig::AbstractParamDescriptionConstPtr> &DepthSensorPoseConfig::__getParamDescriptions__()
  {
    return __get_statics__()->__param_descriptions__;
  }

  inline const std::vector<DepthSensorPoseConfig::AbstractGroupDescriptionConstPtr> &DepthSensorPoseConfig::__getGroupDescriptions__()
  {
    return __get_statics__()->__group_descriptions__;
  }

  inline const DepthSensorPoseConfigStatics *DepthSensorPoseConfig::__get_statics__()
  {
    const static DepthSensorPoseConfigStatics *statics;

    if (statics) // Common case
      return statics;

    boost::mutex::scoped_lock lock(dynamic_reconfigure::__init_mutex__);

    if (statics) // In case we lost a race.
      return statics;

    statics = DepthSensorPoseConfigStatics::get_instance();

    return statics;
  }


}

#endif // __DEPTHSENSORPOSERECONFIGURATOR_H__