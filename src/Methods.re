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
type spotifyRegion;

[@bs.module "sonos"] [@bs.scope "SpotifyRegion"]
external regionEurope: spotifyRegion = "EU";

[@bs.send]
external setSpotifyRegion: (sonosDevice, spotifyRegion) => unit =
  "setsetSpotifyRegion";

[@bs.send]
external getVolume: (sonosDevice, unit) => Js.Promise.t(float) = "getVolume";
[@bs.send]
external currentTrack: (sonosDevice, unit) => Js.Promise.t('a) =
  "currentTrack";
[@bs.send]
external queue: (sonosDevice, string, int) => Js.Promise.t('a) = "queue";
[@bs.send]
external queueAsLast: (sonosDevice, string) => Js.Promise.t('a) = "queue";
[@bs.send]
external getCurrentState: (sonosDevice, unit) => Js.Promise.t(string) =
  "getCurrentState";
[@bs.send]
external selectQueue: (sonosDevice, unit) => Js.Promise.t(bool) =
  "selectQueue";
[@bs.send]
external selectTrack: (sonosDevice, int) => Js.Promise.t(bool) =
  "selectTrack";
[@bs.send]
external searchMusicLibrary: (sonosDevice, string, string) => Js.Promise.t('a) =
  "searchMusicLibrary";

[@bs.send] external play: (sonosDevice, unit) => Js.Promise.t(bool) = "play";
[@bs.send]
external pause: (sonosDevice, unit) => Js.Promise.t(bool) = "pause";
[@bs.send]
external flush: (sonosDevice, unit) => Js.Promise.t(bool) = "flush";
[@bs.send]
external setVolume: (sonosDevice, float) => Js.Promise.t('a) = "setVolume";
[@bs.send]
external getQueue: (sonosDevice, unit) => Js.Promise.t('a) = "getQueue";
[@bs.send]
external setMuted: (sonosDevice, bool) => Js.Promise.t(bool) = "setMuted";
[@bs.send] external next: (sonosDevice, unit) => Js.Promise.t(bool) = "next";
[@bs.send]
external previous: (sonosDevice, unit) => Js.Promise.t(bool) = "previous";
