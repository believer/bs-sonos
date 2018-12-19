type sonosDevice;

/* Create device */
[@bs.new] [@bs.module "sonos"]
external speaker: string => sonosDevice = "Sonos";

let device = ip => speaker(ip);

/* Group Control */
[@bs.deriving abstract]
type groupReqArgs = {
  [@bs.as "InstanceID"]
  instanceId: int,
  [@bs.as "DesiredVolume"]
  volume: string,
};

type sonosGroup = {
  .
  [@bs.meth] "_request": (string, groupReqArgs) => Js.Promise.t(Js.Json.t),
};

[@bs.new] [@bs.module "sonos"] [@bs.scope "Services"]
external groupRenderingControl: string => sonosGroup = "GroupRenderingControl";

/* Methods */

[@bs.module "sonos"] [@bs.scope "SpotifyRegion"]
external regionEurope: string = "EU";

[@bs.send] external setSpotifyRegion: (sonosDevice, string) => unit = "";

[@bs.send]
external getVolume: (sonosDevice, unit) => Js.Promise.t(float) = "";
[@bs.send]
external currentTrack: (sonosDevice, unit) => Js.Promise.t('a) = "";
[@bs.send]
external queue: (sonosDevice, string, int) => Js.Promise.t('a) = "";
[@bs.send]
external queueAsLast: (sonosDevice, string) => Js.Promise.t('a) = "queue";
[@bs.send]
external getCurrentState: (sonosDevice, unit) => Js.Promise.t(string) = "";
[@bs.send]
external selectQueue: (sonosDevice, unit) => Js.Promise.t(bool) = "";
[@bs.send]
external selectTrack: (sonosDevice, int) => Js.Promise.t(bool) = "";
[@bs.send]
external searchMusicLibrary: (sonosDevice, string, string) => Js.Promise.t('a) =
  "";

[@bs.send] external play: (sonosDevice, unit) => Js.Promise.t(bool) = "";
[@bs.send] external pause: (sonosDevice, unit) => Js.Promise.t(bool) = "";
[@bs.send] external flush: (sonosDevice, unit) => Js.Promise.t(bool) = "";
[@bs.send] external setVolume: (sonosDevice, float) => Js.Promise.t('a) = "";
[@bs.send] external getQueue: (sonosDevice, unit) => Js.Promise.t('a) = "";
[@bs.send] external setMuted: (sonosDevice, bool) => Js.Promise.t(bool) = "";
[@bs.send] external next: (sonosDevice, unit) => Js.Promise.t(bool) = "";
[@bs.send] external previous: (sonosDevice, unit) => Js.Promise.t(bool) = "";
